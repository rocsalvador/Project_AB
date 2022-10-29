import matplotlib.pyplot as plt
import pandas as pd
import sys

filename = sys.argv[1]

df = pd.DataFrame(pd.read_csv(filename))
 
# Figure Size
fig = plt.figure(figsize =(10, 7))
 
# Horizontal Bar Plot
plt.bar(df['length'], df['n_sequences'])

# Show Plot
plt.show()