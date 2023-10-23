#!/bin/bash

source ~/opt/anaconda3/etc/profile.d/conda.sh

cd ~/Development/24H1_QE_Coding

echo "\nPulling from git..."
git pull

echo "\nRunning process_checker.py..."
python ./process_checker.py


echo "\nPushing to git..."
timestamp=$(date +"%Y-%m-%d %T")
git add .
git commit -m "Auto commit process_checker at $timestamp"
git push