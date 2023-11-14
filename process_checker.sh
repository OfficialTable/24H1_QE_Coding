#!/bin/bash

PATH+=:/Users/jeongsik/opt/anaconda3/bin
timestamp=$(date +"%Y-%m-%d %T")

echo ""
echo "Running process_checker.sh at $timestamp..."

cd ~/Development/24H1_QE_Coding

# git config --global user.email "jeongsikpyo@gmail.com"
# git config --global user.name "OfficialTable"

echo ""
echo "Pulling from git..."
git pull

echo ""
echo "Running process_checker.py..."
python process_checker.py

echo ""
echo "Pushing to git..."
git add .
git commit -m "Auto commit process_checker at $timestamp"
git push

echo ""
echo "Finished!"
