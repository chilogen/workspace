import re, os, shutil

HisPath = input("Enter History File Path: ")

with open(HisPath, 'r') as HisFile:
	src=HisFile.read().split('\n')

dst = src

cmd = input("Use pattern file?[Y/N]: ")

if cmd.lower()=='n':
	print("Now you should add pattern manully")

	while True:
		cmd = input("Continue add Pattern or Redo?[Y/N/R]: ")
		
		if cmd.lower() == "n":
			break
		elif cmd.lower() == "r":
			dst = src
			continue
		elif cmd.lower() == "y":
			pattern = re.compile(input("Enter a pattern: "))
		else:
			continue


		src = dst
		dst = [x for x in src if not pattern.match(x)]
		for x in dst:
			print(x)

else:
	PatternPath = input("Enter Pattern File Path: ")
	with open(PatternPath, "r") as PatternFile:
		pat = PatternFile.read().split('\n')

	for x in pat:
		pattern = re.compile(x)
		src = dst
		dst = [it for it in src if not pattern.match(it)]

with open('tmp', 'w') as TmpFile:
	for x in dst:
		TmpFile.write(x + '\n')

cmd = input("Do you want to use tmp overwrite user history?[Y/N]: ")


if cmd.lower() == "y":
	shutil.compile(HisPath,"history.backup")
	shutil.move("tmp",HisPath)
	print("Origin has been Update and backup as history.backup")