 #!/bin/bash          

function quit
{
	echo "...exiting the script..."
	exit 1
}




declare -a Mfrom
declare -a Mupto
declare -a Mstep

declare -a Kfrom
declare -a Kupto
declare -a Kstep

declare -a Nfrom
declare -a Nupto
declare -a Nstep

declare -a whereToPutA
declare -a whereToPutB
declare -a whereToPutY

#./spmv "$one_hundred" "$one_hundred" "$one_hundred" "$msmc" "$msmc" "$msmc"
testFile="tests.txt"

# read the configuration file
echo "The file with test cases specifications (tests.txt):"
regex="tests set #([0-9]+): ([0-9]+) ([0-9]+) ((\*|)[0-9]+) ([0-9]+) ([0-9]+) ((\*|)[0-9]+) ([0-9]+) ([0-9]+) ((\*|)[0-9]+) ([aMD][a-zA-Z]*) ([aMD][a-zA-Z]*) ([aMD][a-zA-Z]*)"
regexMulutiplied="(\*|)([0-9]+)"
lineNumber=-2
while IFS='' read -r line || [[ -n "$line" ]]; do
	lineNumber=$((lineNumber + 1))
    if [[ "$lineNumber" -gt -1 ]]; then
    	echo "$lineNumber: $line"
	    if [[ "$line" =~ $regex ]]; then
	    	echo "test set number: ${BASH_REMATCH[1]}"
	    	testSuiteNumber=${BASH_REMATCH[1]}
	    	echo "M will start at: ${BASH_REMATCH[2]}"
	    	Mfrom[$lineNumber]=${BASH_REMATCH[2]}
	    	echo "M will move up to: ${BASH_REMATCH[3]}"
	    	Mupto[$lineNumber]=${BASH_REMATCH[3]}
	    	if [[ "${BASH_REMATCH[4]:0:1}" = "*" ]]; then
	    		echo "M will be multiplied by: ${BASH_REMATCH[4]:1}"
	    	else
	    		echo "M will have a step: ${BASH_REMATCH[4]}"
	    	fi
	    	Mstep[$lineNumber]=${BASH_REMATCH[4]}
	    	#anywhere="a"
	    	#echo "$Mfrom"
	    	
	    	#echo "new Mfrom: $Mfrom"
	    	#echo ${BASH_REMATCH[6]}
	    	#echo "MATCH"
	    
	    	echo "K will start at: ${BASH_REMATCH[6]}"
	    	Kfrom[$lineNumber]=${BASH_REMATCH[6]}
	    	echo "K will move up to: ${BASH_REMATCH[7]}"
	    	Kupto[$lineNumber]=${BASH_REMATCH[7]}
	    	if [[ "${BASH_REMATCH[8]:0:1}" = "*" ]]; then
	    		echo "K will be multiplied by: ${BASH_REMATCH[8]:1}"
	    		#if [[ "${BASH_REMATCH[8]:1}" = "1" ]]; then
	    		#	echo "!!!ERROR!!! seems like your step multiplies by 1 which will create an infinte loop"
	    			#quit
	    		#fi
	    	else
	    		echo "K will have a step: ${BASH_REMATCH[4]}"
	    		#if [[ "${BASH_REMATCH[8]}" = "0" ]]; then
	    		#	echo "!!!ERROR!!! seems like your step is 0 which will create an infinte loop"
	    		#	quit
	    		#fi
	    	fi
	    	Kstep[$lineNumber]=${BASH_REMATCH[8]}

	    	echo "N will start at: ${BASH_REMATCH[10]}"
	    	Nfrom[$lineNumber]=${BASH_REMATCH[10]}
	    	echo "N will move up to: ${BASH_REMATCH[11]}"
	    	Nupto[$lineNumber]=${BASH_REMATCH[11]}
	    	if [[ "${BASH_REMATCH[12]:0:1}" = "*" ]]; then
	    		echo "N will be multiplied by: ${BASH_REMATCH[12]:1}"

	    	else
	    		echo "N will have a step: ${BASH_REMATCH[12]}"
	    	fi
	    	Nstep[$lineNumber]=${BASH_REMATCH[12]}


	    	whereToPutA[$lineNumber]=${BASH_REMATCH[14]}
	    	#echo "A - ${BASH_REMATCH[14]}"
			case "${BASH_REMATCH[14]:0:1}" in
			("a") echo "A will be placed on both MSMC and DDR in separate test cases" ;;
			("M") echo "A will be placed on MSMC" ;;
			("D") echo "A will be placed on DDR" ;;
			(*) echo "I do not khow where to put A (you said ${BASH_REMATCH[14]})" quit;;
			esac

			whereToPutB[$lineNumber]=${BASH_REMATCH[15]}
			#echo "B - ${BASH_REMATCH[15]}"
			case "${BASH_REMATCH[15]:0:1}" in
			("a") echo "B will be placed on both MSMC and DDR in separate test cases" ;;
			("M") echo "B will be placed on MSMC" ;;
			("D") echo "B will be placed on DDR" ;;
			(*) echo "I do not khow where to put B (you said ${BASH_REMATCH[15]})" quit;;
			esac

			whereToPutY[$lineNumber]=${BASH_REMATCH[16]}
			#echo "Y - ${BASH_REMATCH[16]}"
			case "${BASH_REMATCH[16]:0:1}" in
			("a") echo "Y will be placed on both MSMC and DDR in separate test cases" ;;
			("M") echo "Y will be placed on MSMC" ;;
			("D") echo "Y will be placed on DDR" ;;
			(*) echo "I do not khow where to put B (you said ${BASH_REMATCH[16]})" quit;;
			esac
	    else
	    	echo "Test set information does not match the following pattern:"
	    	echo "tests set <number>: <starting value of M> <biggest value of M> <step (put '*2' if step is exponential)> <starting value of M> <biggest value of M> <step (put '*2' if step is exponential)> <starting value of K> <biggest value of K> <step (put '*2' if step is exponential)> <where to put A ('MSMC' for MSMC, 'DDR' for DDR and 'all' for MSMC in one test case and DDR in the other)> <where to put B ('MSMC' for MSMC, 'DDR' for DDR and 'all' for MSMC in one test case and DDR in the other)> <where to put Y ('MSMC' for MSMC, 'DDR' for DDR and 'all' for MSMC in one test case and DDR in the other)>"
	    	quit
    	fi
    fi

    

done < "$testFile"

echo ""
echo "Is the test suit information was processed correctly? [Y/n]"
read userApproval

if [[ "${userApproval:0:1}" = "n" ]]; then
	echo ""
	echo "The user has not approved of the data!"
	quit
else
	echo "The user has approved the data"
fi

#echo ${Mfrom[*]}
#echo ${whereToPutA[*]}
#echo ${Kstep[*]}
#echo ${#Kstep[@]}

declare -a memroryParameters
case "${whereToPutA[$lineNumber][0]:0:1}" in
("a") memroryParameters+=("MSMC") memroryParameters+=("DDR");;
("M") memroryParameters+=("MSMC") ;;
("D") memroryParameters+=("DDR") ;;
(*) echo "Unknown error" quit;;
esac

#echo ${memroryParameters[*]}


length=${#memroryParameters[@]}
#echo "length is $length"
case "${whereToPutB[$lineNumber][0]:0:1}" in
("a")
for i in `seq 0 $((length - 1))`;
do
	#echo "$i - ${memroryParameters[$i]}"
	memroryParameters+=("${memroryParameters[$i]} MSMC")
	memroryParameters[$i]+=" DDR"	
done ;;
("M") 
for i in `seq 0 $((length - 1))`;
do
	memroryParameters[$i]+=" MSMC"	
done ;;
("D")
for i in `seq 0 $((length - 1))`;
do
	memroryParameters[$i]+=" DDR"	
done ;;
(*) echo "Unknown error" quit;;
esac



length=${#memroryParameters[@]}
#echo "length is $length"
case "${whereToPutY[$lineNumber][0]:0:1}" in
("a")
for i in `seq 0 $((length - 1))`;
do
	#echo "$i - ${memroryParameters[$i]}"
	memroryParameters+=("${memroryParameters[$i]} MSMC")
	memroryParameters[$i]+=" DDR"	
done ;;
("M") 
for i in `seq 0 $((length - 1))`;
do
	memroryParameters[$i]+=" MSMC"	
done ;;
("D")
for i in `seq 0 $((length - 1))`;
do
	memroryParameters[$i]+=" DDR"	
done ;;
(*) echo "Unknown error" quit;;
esac

<<PRINTOUTARRAY
echo "output array"
for i in `seq 0 ${#memroryParameters[@]}`;
do
	echo ${memroryParameters[$i]}
done 
PRINTOUTARRAY

# now array memroryParameters of strings with all memory parameters for A, B, Y

length=${#Mfrom[@]}

i=0
j=0
l=0
p=0
t=0
regex="([a-zA-Z]+) ([a-zA-Z]+) ([a-zA-Z]+)"
fail=0
#for loop iterating through test sets

for i in `seq 0 $((length - 1))`;
do
	echo "test set #$i"
	j=${Mfrom[$i]}
	while [ $j -le ${Mupto[$i]} ]
	do
		#echo "current M $j"

		l=${Kfrom[$i]}
		while [ $l -le ${Kupto[$i]} ]
		do 
			#echo "current K $l"

			p=${Nfrom[$i]}
			while [ $p -le ${Nupto[$i]} ]
			do
				#echo "current N $p"				

				#loop thtough all possible A, B, Y parameters
				for t in `seq 0 $((${#memroryParameters[@]}-1))`;
				do
					echo "./spmv $j $l $p ${memroryParameters[t]}"
					#./spmv "$j" "$l" "$p" "${memroryParameters[t]}"
					if [[ "${memroryParameters[t]}" =~ $regex ]]; then
						fail=`./spmv "$j" "$l" "$p" "${BASH_REMATCH[1]}" "${BASH_REMATCH[2]}" "${BASH_REMATCH[3]}"`
						echo "did it fail? $fail"

					else
						echo "!!!INTERNAL ERROR!!! memroryParameters array in the bash script was not formed correctly. Aborting now..."
						quit
					fi
					
					sleep 1
				done


				#find out how to increment N: multiplying or adding a step
				if [[ "${Nstep[$i]:0:1}" = "*" ]]; then
					echo ""
					p=$((p*${Nstep[$i]:1}))
				else
					p=$((p+${Nstep[$i]}))
				fi


			done


			#find out how to increment K: multiplying or adding a step
			if [[ "${Kstep[$i]:0:1}" = "*" ]]; then
				echo ""
				l=$((l*${Kstep[$i]:1}))
			else
				l=$((l+${Kstep[$i]}))
			fi
		done

		#find out how to increment M: multiplying or adding a step
		if [[ "${Mstep[$i]:0:1}" = "*" ]]; then
			echo ""
			#multip
			j=$((j*${Mstep[$i]:1}))
		else
			j=$((j+${Mstep[$i]}))
		fi
	done
done 




