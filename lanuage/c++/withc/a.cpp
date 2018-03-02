class student
{
        public:
                student():a1('a'),a2('b'),a3('c'){}
                void set();
        private:
                char a1,a2,a3;
};
extern char b[3];
void student::set()
{
	b[0]=a1;
	b[1]=a2;
	b[2]=a3;
}
