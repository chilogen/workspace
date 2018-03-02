class NetworkException(Exception):
	def __init__(self,arg):
		self.arg=arg
class EnvirmentException(Exception):
	def __init__(self,arg):
		self.arg=arg
class FileExistsException(Exception):
	def __init__(self,arg):
		self.arg=arg
	