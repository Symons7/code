#!/usr/bin/python

import sys

def divide(a, b):
	temp = a / b
	sys.stdout.write(str(temp))
	reminder = a % b
	if reminder == 0:
		return
	sys.stdout.write(".")
	reminder_pos = {}
	result = []
	while reminder != 0:
		if reminder_pos.has_key(reminder):
			break
		reminder_pos[reminder] = len(result)
		reminder = reminder * 10
		cur_div = reminder / b
		result.append(cur_div)
		reminder = reminder % b
	if reminder == 0:
		for i in result:
			sys.stdout.write(str(i))
	else:
		repeat_start = reminder_pos[reminder]
		for i in range(len(result)):
			if i == repeat_start:
				sys.stdout.write("(")
			sys.stdout.write(str(result[i]))
		sys.stdout.write(")")
	print
	return

a,b = map(int, raw_input("Input 2 positive integers:").split())
divide(a, b)
