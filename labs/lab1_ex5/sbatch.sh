#!/usr/bin/env bash

#SBATCH --job-name=lab1_ex5
#SBATCH --output=stdout_%j.out
#SBATCH --error=stderr_%j.err
#SBATCH --partition=edu5
#SBATCH --nodes=1
#SBATCH --gres=gpu:0
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

name=$(hostname)
./hi_from_host.elf "${name}"
