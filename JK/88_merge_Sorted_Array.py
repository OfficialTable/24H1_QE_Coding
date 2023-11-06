{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [],
   "source": [
    "def merge(nums1, m, nums2, n) -> None:\n",
    "    for l in range(len(nums1), m, -1):\n",
    "        nums1.pop()\n",
    "    for l in range(len(nums2), n, -1):\n",
    "        nums2.pop()        \n",
    "    \n",
    "    \n",
    "    nums1.extend(nums2)\n",
    "    nums1.sort()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {},
   "outputs": [],
   "source": [
    "nums1 = [1,2,3,0,0,0]\n",
    "m = 3\n",
    "nums2 = [2,5,6]\n",
    "n = 3\n",
    "merge(nums1, m, nums2, n)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[1, 2, 2, 3, 5, 6]"
      ]
     },
     "execution_count": 5,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "nums1"
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
