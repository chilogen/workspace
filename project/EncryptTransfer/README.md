# 文件加密传输---综合课程设计

* 设计目标  
使用RSA非对称加密、TCP协议、Linux多线程，实现文件加密传输

* C\S结构  
    * **Server**:  
    监听6666端口，由TCP从客户端获得密钥，向客户端发送新端口号，在新端口上等待客户连接（超时拒绝），并传  
    输文件
    * **Client**  
    生成密钥（或以前的），将公钥通过6666端口发送给服务端,从服务端获取端口号，在新端口与服务端建立新连接  
    传输文件
    
 
* RSA密钥支持任意位数

* 报文格式:  
    ```html
    part0:say ready
    <flag>   8 bit
    0---wait  1---ok
    ```
    ```html
    part1:header
    <filename>    4096bit
    <publickey>   4096bit
    ```
    ```html
    part2:transfer data
  -----------------------
    <offset>  8bit
    <size>    8sbit
          <data>
              data1 256bit
              data2 256bit
              ....
          </data>
  ----------------------
    <offset>  8bit
    <size>    8bit
          <data>
              data1 256bit
              data2 256bit
              ....
          </data> 16bit
  ----------------------
    <END> 16bit
    
    ```
    
    * 解释：  
        * 每一包代表一个大整数
        * offset---有效位数
        * 大整数分段数（data1,data2...)
        * END 数据传输结束

* 模块
    * RSA  
        - public:  
          RSA(path,flag)  从path读取密钥，0--公钥，1---私钥  
          RSA()  生成公钥、私钥  
          RSA::encrypt(data) return value ---vector<gmp> data---vector<gmp>  
          RSA::decode(data)  return value ---vector<gmp> data---vector<gmp>  
        - private:  
          gmp public_key,private_key  
          RSA::readkey(path)  
          RSA::genkey()
    * NET  
        - public:  
          NET::connect(socket)  
          NET::listen(socket)  
          NET::recv(socketid,bit) joinable pthread  
          NET::send(socketid,bit,data) data--int16_t* joinable pthread
        - private:  
          vector<socket> s  
          vector<uint32_t> free  
          NET::resolve()
    * IO  
        - public:
          IO::writestream  
          IO::readstream
          IO::setsize(int)  
        - private:  
          string buffer  
          int size  
    * FUN  
        b2g(bit*,len)   return gmp  
        g2b(gmp)        return (bit*.len)
        
        
        
* problem
    * SIGPIPE singnal occur on server when client force exit
    > use signal(SIGPIPE,signal_call_back_func(SIG_IGN)) and the check socket every time when read data
    
    * mutiple definition in bss section when declare an value in common header file
    > declare value in cpp file and use extern in header file
    
    * mess code when comunicate
    > reset buffer before every transfer
    
    * SIGPIPE signal occur randomly when client write to server