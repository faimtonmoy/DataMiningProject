import pandas as pd
from pandas import read_csv
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import fpgrowth
import csv
import time
acc_list_of_arrays=[]
with open('chess.csv', 'r') as file:
    dataset = csv.reader(file, delimiter=' ')
    for row in dataset:
        temp=[element for element in row]
        temp= temp[:-1]
        print(temp)
        acc_list_of_arrays.append(temp)
start_time = time.process_time()
te = TransactionEncoder()
te_ary = te.fit(acc_list_of_arrays).transform(acc_list_of_arrays)
df = pd.DataFrame(te_ary, columns=te.columns_)
result= fpgrowth(df, min_support=0.9, use_colnames=True)
print (result)
print ((time.process_time() - start_time),"seconds")



