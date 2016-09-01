import os
import re
import commands
import time

#for loops with continue (from, to (exclusive), step))
for nc in xrange(8, 416, 32):
	for mc in xrange(168, 416, 32):
		if kc < 8:
			continue


#print out	
print "nc - " + str(nc) + " kc = " + str(kc) + " mc = " + str(mc)
print "pool_size - " + str(((mc * kc + nc * kc) * 4))

#open (and implicit close) a file in python		
with open('config/c66x/bli_kernel.h', 'r') as bli_kernel_h :
	#read() reads entire file and returns a huge string 
	filedata = bli_kernel_h.read()
	
	# Replace the target string
	filedata = re.sub('#define BLIS_DEFAULT_MC_S              [0-9]+', ('#define BLIS_DEFAULT_MC_S              ' + str(mc)), filedata)

# Write the file out again
with open('config/c66x/bli_kernel.h', 'w') as bli_kernel_h:
	bli_kernel_h.write(filedata)

print("\n\n\tconfiguring BLIS for c66x (./configure -p ./ c66x)\n")
#run linux command from python
os.system("./configure -p ./ c66x")
#time delay
time.sleep( 3 )

#SSH into a machine, execute some commands there
print("\n\n\tSSHing into the Hawking EVM and runnin the testsuite from there\n")
run_command = " \'cd blis_gitorious/tiblis/testsuite/ && ./test_libblis.x > nc_"+str(nc)+"_mc_"+str(mc)+"_kc_"+str(kc)+".txt \'"
if (commands.getstatusoutput("ssh 156.117.61.23 -p22 -lroot " + run_command )[0] == 0):
	#commands returns a tuple, zeroth element is exit status, 0 - success
	print "success!"
else:
	print "error SSHing into the Hawking board or running the code from it"
		
#input numbers in a string separated by spaces
string_input_list = []
for x in raw_input().split(' '):
    try:
        string_input_list.append(int(x))
    except ValueError:
        pass

#input words in a string separated by spaces
string_input_list = []
for x in raw_input().split(' '):
    string_input_list.append(x)
print string_input_list

#list comprehension
ListOfThreeMultiples = [x for x in range(10) if x % 3 == 0] # Multiples of 3 below 10
#print(ListOfThreeMultiples) -> [0, 3, 6, 9]
