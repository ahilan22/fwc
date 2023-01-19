from itertools import permutations

posList = [0,1,2]
#[0,1,2] reperesents letters written to
#[0,1,2] (persons) respectively 
sampSpace = list(permutations(posList))

#counts the no. of proper placements
def count(inList):
    counter = 0
    for i in inList:
        if i == inList[i]:
            counter += 1
    return counter

#gives cases corresponding to the 'count'
def case_gen(inList, countValue):
    caseGen = []
    for i in range(len(inList)):
        if count(inList[i]) == countValue:
            caseGen.append(inList[i])
    return caseGen

case_2 = case_gen(sampSpace, 1)
print('case(X=1) = ',case_2)
case_3 = case_gen(sampSpace, 3)
print('case(X=3) = ',case_3)

print("Probability is ", (len(case_2)+
    len(case_3))/len(sampSpace))
