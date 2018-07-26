import sys
import os

if len(sys.argv) < 2:
	print '0 close'
	print '2 open'
elif sys.argv[1] == '0':
	os.system('echo 0 | sudo tee /proc/sys/kernel/randomize_va_space')
elif sys.argv[1] == '2':
	os.system('echo 0 | sudo tee /proc/sys/kernel/randomize_va_space')
