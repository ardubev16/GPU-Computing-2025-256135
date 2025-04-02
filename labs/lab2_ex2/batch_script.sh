#!/bin/bash
#SBATCH --partition=edu5
#SBATCH --tasks=1
#SBATCH --cpus-per-task=1
#SBATCH --nodes=1

#SBATCH --job-name=get_time_test
#SBATCH --output=outputs/R-%x.%j.out
#SBATCH --error=outputs/R-%x.%j.err

./bin/get_time_test "$1"
