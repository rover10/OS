#this is a program to generate r* from the alphabet set {ab,c} upto L(n) where value of n is provided by user

alphabet_set=["ab","c"]
list3=[]
def permute(n, list1):
        if n==1:
            print [mem  for mem in list3]
            return
        else:
            k=0
            list2=[]
            [[list2.append(list1[i]+alphabet_set[j]) for j in range(0,2) ]  for i in range(len(list1))]      
            list3.extend(list2)
            list1=list2   
            permute((n-1),list1)
  
        
def input():
    print "\nalphbet set = {ab,c}\n"

    while True:
        try:
            n = int(raw_input("Please enter the value of n: "))
            break
        except ValueError:
            print "please enter a interger only. Try again..."  # Spelling of integer is wrong >> " a interger " make it "an integer".

    print "\n"
    if n==0:
       list3.append("lambda")			  		#We can use capital "E" instead of lambda
    else:
        list3.extend(["lambda","AB","C"])         		#Use small "ab" & "c" instead of capital .
        permute(n, alphabet_set)


input()
