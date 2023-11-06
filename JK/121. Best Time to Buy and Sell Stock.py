{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [],
   "source": [
    "def maxProfit(prices):\n",
    "    cur = prices[0]\n",
    "    ans = 0\n",
    "\n",
    "    for i in range(1,len(prices)):\n",
    "        if cur > prices[i]:\n",
    "            cur = prices[i]\n",
    "        ans = max(ans, prices[i]-cur)\n",
    "\n",
    "    return ans\n",
    "\n",
    "        # 시간 초과\n",
    "        # ans = 0\n",
    "        # for i in range(len(prices)):\n",
    "        #     for k in range(i,len(prices)):\n",
    "        #         if prices[i] < prices[k]:\n",
    "        #             val = prices[k] - prices[i]\n",
    "        #             ans = max(ans, val)\n",
    "\n",
    "        # return ans"
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
    "prices = [7,1,5,3,6,4]\n",
    "maxProfit(prices)"
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
