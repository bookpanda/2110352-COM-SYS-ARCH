start=$(date +%s%N)
./a.out
end=$(date +%s%N)
duration=$(echo "$end - $start" | bc)
echo "Execution time: $duration ns"
