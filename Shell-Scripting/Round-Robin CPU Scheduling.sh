#! /bin/bash

declare -a burstTime
declare -a turnAroundTime
declare -a a

echo -n "Enter number of Process : "
read n

echo -n "Enter time Quantum : "
read timeQuantum 

echo "Enter brust Time: "

for (( i = 1; i <= $n; i++ )); do
	echo -n "Enter brust Time for  $i  :  "
	read burstTime[$i]
    a[$i]=${burstTime[$i]}
    waitingTime[$i]=0	
done

while [[ $n != 0 ]]; do
	for (( i = 1; i <= $n; i++ )); do
		if [[ ${burstTime[$i]} -gt $timeQuantum ]]; then
			burstTime[$i]=$((${burstTime[$i]} - $timeQuantum))
			for (( j = 1; j <= $n; j++ )); do
				if [[ $j -ne $i && ${burstTime[$j]} -ne 0 ]]; then
					waitingTime[$j]=$(( ${waitingTime[$j]} + $timeQuantum ))					
				fi
			done
		else
			for (( j = 1; j <= $n; j++ )); do
				if [[ $j -ne $i && ${burstTime[$j]} -ne 0 ]]; then
					waitingTime[$j]=$(( ${waitingTime[$j]} + ${burstTime[$i]} ))					
				fi
			done
			burstTime[$i]=0
		fi
	done

	sum=0

	for i in burstTime[@a]; do
		sum=$(( $sum + $i))		
	done

	if [[ $sum == 0 ]]; then
		break;
	fi
done

sumesonWaitingTime=0
sumesonTurnAroundTime=0;

for (( i = 1; i <= $n; i++ )); do
	turnAroundTime[$i]=$(( ${waitingTime[$i]} + ${a[$i]} ))			
    sumesonWaitingTime=$(( $sumesonWaitingTime + ${waitingTime[$i]} ))
    sumesonTurnAroundTime=$(( $sumesonTurnAroundTime + ${turnAroundTime[$i]} ))
done

echo Processes$'\t'Burst Time$'\t'Waiting Time$'\t'Turn Around Time$'\n'

for i in 1..10; do
	echo $i
done

for (( i = 1; i <= $n; i++ )); do
	echo process$i$'\t'$'\t'${a[$i]}$'\t'$'\t'${waitingTime[$i]}$'\t'$'\t'${turnAroundTime[$i]}$'\n'
done

echo  The Total Waiting Time :$'\t'$sumesonWaitingTime
echo -n The Average Waiting Time :$'\t'
echo "scale=4;$sumesonWaitingTime/$n" | bc

echo  The Total Turn Around Time :$'\t'$sumesonTurnAroundTime
echo -n The Average Turn Around Time :$'\t'
echo "scale=4;$sumesonTurnAroundTime/$n" | bc


