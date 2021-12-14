''''''
merge=[]
def unpack(words): #[["cd","f","Kl"],["a"]]
        if type(words) == str:
            merge.append(words)
        else:
            for i in words:
                if type(i) == list:
                    return unpack(i)
                else:
                    for m in i:
                        merge.append(m)                          

a=[["cd", "f", "kl"], ["a"]]
unpack(a)
print(merge)
'''

def nthMagicalNumber(n, a, b):
    if n==1:
        return a
    ans=[]
    count=1
    while(len(ans)!=n):
        if count%a==0 or count%b==0:
            ans.append(count)
            count=count+1
    print(ans)
    return ans[-1]
            
        
    
h=nthMagicalNumber(1,2,3)
print(h)
'''
printe("helo")