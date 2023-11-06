{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [],
   "source": [
    "def removeDuplicates(nums):\n",
    "    index = 1  \n",
    "    count = 1  \n",
    "\n",
    "    for i in range(1, len(nums)):\n",
    "        if nums[i] == nums[i - 1]:\n",
    "            count += 1\n",
    "        else:\n",
    "            count = 1\n",
    "        \n",
    "        if count <= 2:\n",
    "            nums[index] = nums[i]\n",
    "            index += 1               \n",
    "\n",
    "    return index  "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "5"
      ]
     },
     "execution_count": 2,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "nums = [1,1,1,2,2,3]\n",
    "removeDuplicates(nums)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "base",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.12"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
