########## Heading - 10 hashes(#)
##### subheading - 5 hashes(#)

########## Microsoft exp 1 
    link - https://www.geeksforgeeks.org/microsoft-interview-experience-for-sde-on-campus-2/

##### 1_1. detecting loop in a linked list, fiding the start and then removing the loop

        Note- in this only when we are detecting the loop, we increment slow by one and fast by two
        when we are finding start or removing loop we start incrementing both at same speed. the only 
        difference now is that the slow starts from head and fast starts from meeting point. 

        1.1 detect loop (floyds cycle finding algorithm)

            in this we take two pointers, fast and slow
            inititally they point to head .
            we increment slow by one step and fast by two steps

            if there is a loop then after some time fast and slow will point to same node
            and that means that there is the loop

            #snippet            

                while(slow && fast && fast->next){
                    slow = slow->next;
                    fast = fast->next->next;
                    if (fast == slow){
                        cout << "cycle deteected" << endl;
                        break;
                    }
                }

        1.2 start of the loop

            first detect the loop. if loop exists then continue else return

            after you are done detecting the loop fast and slow must be pointing to same Node.

            after that set slow pointer to head and then increment both fast and slow by "ONE STEP" (same speed)
            until they meet at the same point (start Node).

            #snippet            

                detectLoop(slow, fast);

                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                //both slow and fast now point at start of loop

                return slow;

        1.3 remove the loop

            first detect the loop.
            Now make slow point to head of the loop. (Note- fast will be at the meeting point)

            Now increment slow and speed at same speed i.e by "ONE STEP".
            since we need to remove the loop we stop at an elment one before the start of the loop. (so that we can make prev->next NULL)

            Note:- need to handle one edge cases. when the starting point is the head Node itself

            #snippet            

                detectLoop(slow, fast);

                slow = head; //fast is at meeting point

                if (slow == fast){ //starting point is the head itself
                    while(fast->next != head)
                        fast = fast->next;
                }else{
                    while(slow->next != fast->next){
                        slow = slow->next;
                        fast = fast->next;
                    }
                }

                fast->next = NULL; //removing the loop

                return head;

        Proof of how we detect start of the cycle:

                                                          slow and fast are currently here
                                                               ^
                                                  +----------> |
                                                  k            |
                                                  + +----------+----------+
                                                  | |                     |
                <----------+ m +--------------->  | |                     |
                                                  v |                     |
               +----------------------------------+-+ start               |
            head                                    ^                     |
                                                    |                     |
                                                    |                     |
                                                    <---------------------+

            after applying floyds algo, slow and fast are at meeting point.

            meeting point is at " k " distance from start of loop 

            let start be at " m " distance from the head .

            let " n " be the length of the loop

            Now since fast is moving at twice the speed
            distance covered by fast = 2 * distance covered by slow 

            m + n*x + k = 2 * ( m + n*y + k)

            here, 
            x = no. of complete cyclic rounds made by fast before meeting slow
            y = no. of complete cyclic rounds made by slow before meeting fast

            from above equaton you get,

            m + k = (x - 2y)*n;

            Which means m+k is a multiple of n. 
            Thus we can write, m + k = i*n or m = i*n - k.

            so that means distance covered by slow pointer m = i*n - k (distance by fast pointer)
            which we can rewrite
            m = (i-1)*n + n-k

            that is RHS means that :
                    " (cover the loop completely i-1 times and then move n-k times). "
                
            this will be equal to "m" steps made by slow.

            hence when we start slow from head and fast from meeting point (at k distacne from start of loop)
            they meet at start of the loop

##### 1_2. first non repeating character in stream on characters

        Given an input stream of A of n characters consisting only of lower case alphabets. 
        The task is to find the first non repeating character, each time a character is inserted to the stream. 
        If there is no such character then append '#' to the answer.

        link - https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

        example
            " aabc "
            this string will be inserted char by char
            so first 'a' is inserted, since it is also first non repeating so 'a' is returned

            no we move on and insert 'a', since a got repeated and we dont have any other char so '#' is returned

            no move on to next i.e 'b', since it is first non repeating we return 'b' 

            next we insert 'c'. now since 'b' is still the first non repeating we return 'b'.
            (now dont get confused here by the fact that 'c' is also non repeating then why we returned 'b',
            because 'b' is still the FIRST non repeating)


            #snippet

            //using map and vector

            string FirstNonRepeating(string A){
                string res = "";
                unordered_set <char> mp; //to store the chars encountered till now
                vector <char> v; //at any point it will store the chars that are currently unique (not repeated)
                //if v is empty means no unique chars till now

                for (char ch: A){
                    if (mp.find(ch) == mp.end()){
                        //first occurence of char
                        v.push_back(ch);
                        mp.insert(ch);
                    }else{

                        auto it = find(v.begin(), v.end(), ch);
                        if (it == v.end()){
                            //this char is already removed from vector
                            //do nothing
                        }else{
                            //it is in vector , so we remove it now
                            v.erase(it);
                        }

                    }
                    //if v is empty then add '#' else add char at front
                    res += (v.empty() ? '#' : v.front());
                }

                return res;
            }

            2. using map and dobly linked list

                note in the above solution in the vector we are inserting at the back and peeking at the front.
                these ops can be performed more effiecient using DOUBLY LINKED LIST

                we will use the same technique as above, but instead of using vector we will
                use DLL.
                and also in the map we storing the reference to the chars pointing to there position
                in the DLL. so that we can perform the delete operation in O(1) time

##### 1_3. infix, postfix, prefix
        
        How to handle unary operators: https://stackoverflow.com/questions/17254080/infix-to-postfix-algorithm-that-takes-care-of-unary-operators

        all the algo below assumes that operators are binary.

        in the infix notation if operator comes after another operator or it is the first char in the expression
        then it is the unary operator
        to handle unary operators we convert them to "an operand and operator".
        example: 
                4*-5

                here - is acting as unary so we replace '-' with " -1 and * "
                4*(-1*5)

        3.1 convert infix to postfix (using stack)

            example 
                infix = a+b*c+d
                postfix = abc*+d+

                infix = (a+b)*(c+d)
                postfix = ab+cd+*

            so in this we will maintain a result string and a stack

                Note : the stack will only contain parenthesis and oeprators, operands are directly added to resdult
                string

                1. traverse the string from left to right
                2. if char is operand add to res
                3. if char is operator then we need to add to stack but before that we need to check some conditions:
                    if operator on top of stack has more or same precedence(and associatvity) then current op.
                        then pop from stack and add to res.
                        remove all such operators from the stack
                    if operator on top has less precedence then current op.
                        push current to the stack
                4. if char is '(' opening parenthesis, add it to stack
                5. if char is ')' closing parenthesis:
                    pop from stack and add to res. until you encounter '('
                    pop the '(' then stop

                6. when you are done parsing the string, if stack is not empty then empty the stack and add
                    all operators to the res
            
        3.2 infix to prefix (using stack)

            infix = a+b*c+d
            postfix = abc*+d+
            prefix = ++a*bc+d

            infix = (a+b)*(c+d)
            postfix = ab+cd+*
            prefix = *+ab+cd

            steps:

            1. Reverse the infix expression, 
                Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
                so you need to change '(' to ')' and ')' to '('
            2. convert the reversed string to postfix
                While converting to postfix expression, instead of using pop operation to pop 
                operators with greater than or equal precedence, here we will only pop the operators 
                from stack that have greater precedence.

            3. reverse the postfix expression

            infix expression --> reverse --> postfix --> reverse the postfix == prefix expression

        3.3 prefix to postfix

            infix = (a+b)*(c+d)
            postfix = ab+cd+*
            prefix = *+ab+cd

            to convert prefix to postfix, we will again use stack..
            Note : In this conversion we will push "OPERANDS" to stack. in earlier conversion inffix to prefix
                   infix to postfix we were pushing operators to stack. but this time it is opposite

            1. read the given string from RIGHT to LEFT
            2. if symbol is operand add it to stack
            3. if symbol is operator then pop two operands from stack, combine the operands with operator and push
                that back to stack:
                    lets say two symbols popped from stack are a, b and operator is +
                    then we will combine them in postfix form = ab+ and push this "ab+" in the stack
            4. repeat untill all symbols are scanned
            5. stack will contain the postfix expression

        3.4 postfix to prefix

            post fix to prefix same as above but this time we read the postfix expression from LEFT TO RIGHT.
            and this time we combine the operands from the stack with operator in prefix manner
                    lets say two symbols popped from stack are a, b and operator is +
                    then we will combine them in prefix form = +ab and push this "+ab" in the stack

        3.4 evalauate infix, prefix, postfix

            to evaluate infix we convert it to either postfix or prefix first then evalute the converted form.

            to evaluate postifix read string from left to right, 
                if char is operand push to stack,
                if char is operator pop two operands from the stack, apply the operator to the operands.
                push the res to stack

            to evaluate prefix read string from right to left
                and do the same step as we did in postfix evaluation

##### 1_4. Decode a string recursively encoded as count followed by substring
    link - https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/

    code file name - 4decodeStringCountFollowedBySubstring.cpp

    An encoded string (s) is given, the task is to decode it. The pattern in which the strings 
    are encoded is as follows. 

    Input : str[] = "1[b]"
    Output : b

    Input : str[] = "2[ab]"
    Output : abab

    Input : str[] = "2[a2[b]]"
    Output : abbabb

    Input : str[] = "3[b2[ca]]"
    Output : bcacabcacabcaca

    4.1 using two stacks 

        we use two stacks one for integers and one for string.

        1. wheenever we see a number we add it to number stack.
        2. when we see '[' or char between 'a' - 'z' we push it to string stack
        3. when we see ']', we pop from the string stack until we see '[' and then we pop '[' also
            we concatenate the pooped items in the order.
            Note - string popped will be in reverse order, for now wwe leave it as it is.
            let the popped string be "temp"
        4. then from the integer stack we pop the number 'num'
        5. now we repeat or concatenate "temp" for 'num' times. and then push it back to stack and move to
            next char.

        6. after we have proccessed all chars now the stack/vector may have more than one strings.
            (consider this example 1[b]1[b]1[a], in this case final stack will be {b,b,a})
            now we loop through this stack/vector from 1st to last entry, and concatenate all these
            individual strings into one final string
                BUT
            before concatenating these if you rememver these strings are in reverse order, so we need to
            reverse it again to bring it back to normal and then concatenate it with final string

    4.2 using single stack

        same as above, just one difference that instead of keeping a seperate stack for nums, we push it
        in the same stack. 
            when we encounter ']' we pop from stack until '[' to get the string,
            now after '[' we will have our number

########## Microsoft Exp - 2

##### 2_1 sort array containing 0, 1, and 2 only (Dutch National flag problem)

    In this we are given an array which can contain only 0 ,1 and 2
    example:
            [0, 1, 2, 1, 0, 1]

        we need to sort this array    

            [0, 0, 2, 1, 1 1]


        2_1_1 method 1 find count 

            in this we find count of 0s, 1s and 2 in the array
            and then in the array we first add 0s for given count, then we add 1 and then 2

            this requires two time traversal one for finding the count
            and second for writing 0,1,2 in order

        2_1_2 method two using two pointers, three way partitioning

            here we use two pointers start and end
            inititally start = 0
                        end = n-1 

            at any time we maintain the array such that
                all elements before start are 0
                all elements after end will be 2
                and elements between start and end is currently unexplored

            we start i from 0 to end
                if arr[i]  == 0:
                    then swap(arr[i], arr[start]);
                    start++;
                    i++;
                else if arr[i] == 2:
                    then swap(arr[i], arr[end]);
                    end--;
                    // Note: here we dont incremnt i, because now at ith position we have the elment which was at end
                    // and we havent explored this element at 'end' so if we increment 'i', we will miss this
                    // so to give a chance to this element we stay at i 

                    // we incremented i in the previous 'if' when we swaped with start, because since i is coming
                    // from behind so that element must have already been proccessed, we can increment in i in previous
                    // case with no problem

            2_1_3 do the same if it was a linked list

                in case of linked list, 
                    if cur node is 0 then insert it at front
                    if cur node is 2 then insert at end


########## Microsoft Exp - 3

    link - https://www.geeksforgeeks.org/microsoft-interview-experience-for-sde-3/

##### 3_1 recover a tree from preorder traversal string
    link - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/solutions/274633/c-simple-recursive-preorder/
        
    // "1-2--3--4-5--6--7"
    //dashes represent the current level/depth of current node       
    // string above represents this tree
            1
        2       5
     
    3       4 6     7


    The idea is pretty simple, at each depth make sure that the number
    of '-' is same as the depth, if it's not return NULL else continue 
    the recursive preorder traversal.

    In general the preorder traversal through recursion is:
    #snippet

        void preorder(Treenode* root)
        {   
            //first part - processing current node
            if(!root)
            {
                cout<<"NULL";
                return;
            }
            cout<<root->val;

            //second part - recurssion for left and right
            preorder(root->left);
            preorder(root->right);
        }

    What we are doing here is the same, just imagine the string is in form of a tree and 
    make sure that the boundaries for print(case above)/set root->val(this case) or returning/printing 
    NULL are set right (according to the question).


    int i=0; //global index of string s
    TreeNode* solve(int d,string &s){ //d is the current depth

        //first part - processing current node

        if(i>=s.length())return NULL;
        string str="";
        int x=0; //x will store depth of this node
        int st=i; //storing previous posititon of i, if we need to reset i 
        while(s[i]=='-'){
            i++;
            x++;
        }
        if(x!=d){ //if current depth is not equal to depth of this node, so return NULL
            i=st; //reset i
            return NULL;
        }
        while(i<s.length()&&s[i]!='-'){ //extract the num at current node
            str+=s[i];
            i++;
        }
        
        int val=stoi(str);
        TreeNode* temp=new TreeNode(val);


        //second part - recurssion for left and right

        temp->left=solve(d+1,s);
        temp->right=solve(d+1,s);
        return temp;
    }
    TreeNode* recoverFromPreorder(string s) {
        return solve(0,s);
    }

##### 3_2 given array of coins, get max number of coins you can pick
    
    Question 1: Given an array of repressing gold coins at each position, for any position you can take 
    half of the value at that index an infinite number of times. You have k chances, 
    find the max gold coin you can collect.

    solution

        1. Put all values in a priority queue.
        2. do this for k times:
            2.1 pick top of the queue.
            2.2 take add half of top to the result.
            2.3 remove top from priority queue
            2.4 add top/2 to priority queue

##### 3_3 Iterative Letter Combinations of a Phone Number

    link - https://www.geeksforgeeks.org/iterative-letter-combinations-of-a-phone-number/

    Given an integer array containing digits from [0, 9], the task is to print all possible 
    letter combinations that the numbers could represent. 

    A mapping of digit to letters (just like on the telephone buttons) is being followed. Note
    that 0 and 1 do not map to any letters.

    mappings:
        vector <string> mp { 
                            "0", //0
                            "1", //1
                            "abc", //2
                            "def", //3
                            "ghi", //4
                            "jkl", //5
                            "mno", //6
                            "pqrs", //7
                            "tuv", //8
                            "wxyz" //9
                            };

    Input: nums[] = {2, 3} 
    Output: ad ae af bd be bf cd ce cf

    Input: nums[] = {9} 
    Output: w x y z 

        3_3_1 Using DFS and backtracking
            let say the given input arr is nums

            we start from i = 0;
            
            if (i >= nums.size())
                we have generated the cur_str, and add it to solution
            else
                for ch in mp[nums[i]]:
                    cur_str += ch
                    f(i+1, cur_str); //recursive call
                    cur_str.pop_back(); //backtrack

        3_3_2 Using BFS

            we start from empty string ""

            add "" to the queue;
            while queue not empty:
                front = q.front() q.pop();
                if (front.size() == nums.size())
                    add front to res;
                else
                    for ch in mp[front.size()]:
                        temp = front + ch;
                        queue.push_back(temp);

            return res;

##### 3_4  LLD round, was asked to implement malloc() and free() functions for Linux
##### 3_5  LLD round, was asked to implement a rate limiter, to allow only 100 requests per second from a unique IP.
    
########## Microsoft Exp - 4
    link - https://www.geeksforgeeks.org/microsoft-idc-interview-experience-set-69-for-sde/?ref=rp

##### 4_1 search an element in infinite sorted array

    the array is sorted but we do not know the size of the array.
    so we cannot directly apply binary search.

    so the basic idea is inititally take some range based on your choice lets say the range is 100
    so i will set my low as 0 and high = 100, then i will compare the element with the element at index high
    if element < arr[high]:
        apply binarySearch(low, high, element);
    else 
        set low = high
        high = 2*high
    repeat above steps until elment is found

    generaly the in starting the high is intialised as '0', then as search progresses we keep on doubling
    it.

    Complexity analysis:
        Let p be the position of element to be searched. Number of steps for finding 
        high index ‘h’ is O(Log p). The value of ‘h’ must be less than 2*p. 
        The number of elements between h/2 and h must be O(p). Therefore, time complexity of 
        Binary Search step is also O(Log p) and overall time complexity is 2*O(Log p) which is O(Log p).

##### 4_2 merge two unsorted arrays int sorted array.

    let size of arr1  = n
    let size of arr2 = m

    4_2_1 method 1 would be to concatenate both arrays and then sort 
        
        complexity in this case:
            = merging + sorting array of size n+m
            = n+m + (n+m)log(n+m)
            = n+m + nlog(n+m) + mlog(n+m)
        
    4_2_2 method 2 would be to sort them individually and then merge

        complexity in this case:
            = sorting arr1 + sorting arr2 + merging
            = nlog(n) + mlog(m) + n+m

    so clearly method two is better i.e first sort and then merge

##### 4_3 design how will you implement the most viewed bar in bing search, different approaches

        just like we do in SWC professional,
        create a heap , store the references of the elements in heap in a table

##### 4_4 check if two rectangles overlap

    // Returns true if two rectangles (l1, r1) and (l2, r2)
    // overlap
        bool doOverlap(Point l1, Point r1, Point l2, Point r2)
        {
            // if rectangle has area 0, no overlap
            if (l1.x == r1.x || l1.y == r1.y || r2.x == l2.x || l2.y == r2.y)
                return false;
        
            // If one rectangle is on left side of other
            if (l1.x > r2.x || l2.x > r1.x)
                return false;
        
            // If one rectangle is above other
            if (r1.y > l2.y || r2.y > l1.y)
                return false;
        
            return true;
        }

##### 4_5 Length of the longest substring without repeating characters

    this question is similar to "find the first non repeating character"

    we maintain a map to store currently seen car chars (use arr of size 26, if only small alphabets allowed)

    we also maintain a 'start' variable which basically contains the starting point of current
    substring
    initially start = 0
    also set len = 0 //length of current substring
    res = 0 //to store the max length
    we loop through all the chars starting from left to right

    1. if the char is not in map
        this char is not seen before
        we add it in map
        len++
        res = max(len, res)
    2. if char is in the map
        //this char is already seen before

        consider this example :
            start = 0
            abcdefgh 'c'

            here 'c' is the current char,
            we can see that 'c' has already occrued before
            so we now we shift our window, after the previous occurence of 'c'
            lets say if current window is:

                [abcdefgh]c ....

            now we shift our window and it becomes:

                abc[defghc] ....

            to shift our window we need to do few things 
                1. since we our sifting our window, so we need to remove the elements from the map
                    from start to elment before the repeating char
                    in above example chars from a to b will be marked unvsited/removed

                2. update the start
                    start which was previously at 'a' will now be at 'd' (1 after the repeating char)
                
                3. update the length
                    update len to size of new window
                    len = i - start + 1

##### 4_6 reverse linked list in group of size k

    check the code directly for better understanding :)

##### 4_7 max product subarray

    given an array find the max product subarray.

    example:
        arr - [4,5,6,0,-10,20,10]

        ans: 200

    4_7_1 using algo similar to kadanes (for max sum subarray), but with two traversals 

        this version is like the kadanes algo the only difference is that we need to traverse
        from left to right and then from right to left.

        lets say when array contains even number of -ves, then simply the product of all elements gives max prod
        but when we have odd number of -ves, now we cannot take product of all elements since final prod will
        be -ve.

        so we need to leave either the first -ve or the last -ve (as seen from left)
        when we traverse from left to right, we are automatically including first and excluding last.
        when we do reverse traversal (right to left) we automatically exclude first

        lets say in between we get 0, just like in kadanes algo we make the prod till now to be 1

        our result will be the maximum prod. we got among two traversals

            max_prod = nums[0];
            //left to right
            for (int i=1;i<nums.size();i++){
                prod = prod * nums[i];
                max_prod = max(max_prod, prod);

                if (prod == 0)
                    prod = 1;
            }

            //right to left
            prod = 1;
            for (int i = nums.size()-1; i>=0; i--){
                prod = prod*nums[i];
                max_prod = max(max_prod, prod);

                if (prod == 0)
                    prod = 1;
            }

    4_7_2  in this method we maintain, max prod till now and min prod till now

        int max_prod = nums[0];
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];

        for (int i=1;i<nums.size();i++){
            int temp = max(max(nums[i], max_ending_here*nums[i]), min_ending_here*nums[i]);
            min_ending_here = min(min(nums[i], max_ending_here*nums[i]), min_ending_here*nums[i]);

            max_ending_here = temp;

            max_prod = max(max_ending_here, max_prod);        
        }

        return max_prod;

##### 4_8 building bridges across citites seperated by horizontal river (Dynamic Programming)

    Consider a 2-D map with a horizontal river passing through its center.

    we are given cities in pair from north and south bank
    There are n cities on the northern bank with x-coordinates a(1) … a(n)
    and n cities on the southern bank with x-coordinates b(1) … b(n). 

    we can only connect city at coord a[i] with city at coord b[i]

    Exmaple:
        coordinate of north bank: 6 4 2 1
        coordinate of south bank: 2 3 6 5

    possible bridges we can create are (6,2) or (4,3), (2,6) (1,5)

    but while creating bridges we need to make sure that no two bridges overlap

    example:

        after creating the bridge (6,2) , we can no longer create any other bridge 
        as it will overlap.
        bridge (4,3) overlaps with (6,2) so it is not valid

            WRONG

            1       2       3       4       5       6
                                    +               +
                                    |               |
                    +-------------------------------+
                    |               |
                    |       +-------+
                    +       +
            1       2       3       4       5       6


    lets try another configuration, here we create the bridge, (1,5) and (2,6).
    since they do not overlap so they are valid

        CORRECT

        1       2       3       4       5       6
        +       +
        |       +-------------------------------+
        |                                       |
        +-------------------------------+       |
                                        |       |
                                        +       +
        1       2       3       4       5       6


    we need to return max number bridges we can create without any overlap

    in above example the answer is = 2

    solution:

        Using LIS.

        1. first sort the pairs (north-x, south-x) based on south x coordinates.
        2. then apply LIS on the (north-x).
            the LIS on x is your answer

    coordinate of north bank: 6 4 2 1
    coordinate of south bank: 2 3 6 5

    lets sort according to south

        noth-     6 4 1 2
        south-    2 3 5 6

    now LIS on north

        6 4 1 2

        here we can see the longest increasing subsequence is 2 ( formed by 1 and 2)
        which is our answer.

        so we can create 1-5 and 2-6 bridge without overlap

########## Microsoft Exp - 5

    link - https://www.geeksforgeeks.org/microsoft-idc-interview-experience-set-88-sde-1/?ref=rp


##### 5_1 subarray sum closest to 0.

    Note- this is different from subsequence/subset sum, that one is done using DP

    similar to finding subarray sum equal to 'K'

        when we dont have -ve elements use sliding window
        when we have -ve elements we cannot use sliding window approach
            - instead we use map, we traverse from left to right and store presum or the sum till now in map
                also we check if the difference  = sum_till_now - k exists in the map or not
                if it does then we found our answer

    for finding subarray sum closes to 'k'
        we use  " ordered map " (set) instead of regular hash map
        - we do the same as above save sum till now in map, and in the map we check for lowerbound of the difference
        - note the lower bound gives the element >= then our key, if key == element then no problem.
            but if key > elemment, then we need to decrement the iterator returned by lower bound, and check
            if that element is more closer to 'k' or not

##### 5_2 find LCA in Binary Tree

    Complexity for LCA in BST - O(logn)
    Complexity for LCA in Binary tree - O(n)

##### 5_3 clone list with next and random pointer

    first modify the original list, after every actual node create and insert its clone

    example
        original list

            node1 ----> node2 ----> node3 ----> node4 ---> node5

        modified list

            node1 -----> clone1 ---> node2 ---> clone2 --->node2 ---> clone4 --- and so on

    now we set set the random pointer in the cloned nodes

    inititalise head1 = node1, head2 = clon1 (head of clone list)

    now from above we know that next of actual node points to its clone

        so clone->random = actual->random->next
    
    now in the final step remove the links between actual and clone nodes
    i.e

        clone1 -> clone2 -> clone3 -> clone4
        node1  -> node2  -> node3  -> node4

    you are done

##### 5_4 find union and intersection of two strings

##### 5_5 find max element in array which is first increasing and then decreasing

    apply binary search, check if mid is part of the fist half(insreasing sequence)
    or it is part of the second half (descreasing sequence). and move start and end accordingly

    if (arr[mid] > arr[mid-1]) //part of first haf
    else //part of second half

##### 5_6 check if number if power of 2

    HINT- all numbers that are power of 2 only have one set bit

##### 5_7 check whether lnnked lsit is circular

##### 5_8  check whether two trees are identical


########## Microsoft Exp 6

##### 6_1 convert binary tree to DLL.

    6_1_1 my own recursive approach approach

        To convert a binary tree to DLL, what we need to do is basically connect every node to its
        inorder succesor. and to do this we will use a recursive approach

        In the helper function below we are doing two main things
        1. first is finding the leftmost node in this subtree, which will be the succesor of the parent node.
        2. second is finding the succesor for the current node 

        lets talk about finding the succesor of the Node.
        The succesor will be NULL for the NODES which are " rightmost in there subtree ".
        and if the succesor is NULL for this node, that means its actuall succesor is the parent
        of the current subtree.

            consider this example:
                        
                                                1
                
                                        2               4

                                            3

            its DLL conversion will look like this =   2 -> 3 -> 1 -> 4
            
            Now take a look at Node 3, it is the rightmost node in left subtree,
            and from the below function we will get its inorder succesor to be NULL.
            but in DLL we can see that after 3, 1 comes.
            so we needt to connect it somehow to 1.

            so to handle this case whenever we get the succesor to be NULL we connect that node to the parent.

            else if succesor is not NULL, we just connect the succesor with current Node

            For example for Node 2 , inorder succesor is 3 so we simpply connect it to it

            There is 1 more special Case in this, when the parent is NULL. this will only occur
            for the RIGHT MOST node in the entire tree. 

            For example in above tree for Node 4, its inorder succesor is NULL, as well as parent is NULL
            note that 4 is also the last Node in DLL. so we just make right_pointer of 4 to be NULL.

        Now take a look at the recursive calls

            Node *leftmost = helper(root->left, root);
            Node *succesor = helper(root->right, parent);

            when we call for left subtree we pass the current node as the parent. because current node
            will be the succesor of the rightmost node in the left subtree.

            when we cal for right subtree we pass the  " PARENT " of the current node, again because from the
            right subtree we need to reach the rightmost node of tree, and as discussed above the succesor of 
            rightmost node is parent of the tree.

            Consider this example: 

                                1
                            2
                                3
                its DLL will be:  2->3->1

                1 is succesor of 3 which is on left subtree

                in this starting from 1 we call 2 as
                    f(2, 1)
                then we need to pass 1 further down to 3,
                    f(3, 1)
                        here we connect 1 and 3
        
        Now lets look at the return statement,
        we can see that each time we are returning the leftmost node or the current node if the leftmost
        node is NULL

        this is because, consider the current tree to be the right subtree of a bigger tree, and as we no
        the leftmost node of current tree is succesor of the root of parent tree. i.e we return
        leftmost or current node;

        Node* helper(Node *root, Node *parent){
            if (root == NULL)
                return NULL;
            
            Node *leftmost = helper(root->left, root);
            Node *succesor = helper(root->right, parent);
            
            if (succesor == NULL){
                root->right = parent;
                if (parent)
                    parent->left = root;
            }else{
                root->right = succesor;
                succesor->left = root;
            }
            if (leftmost != NULL)
                return leftmost; //it will become succesor of parent
            return root;
        }

        Node * bToDLL(Node *root)
        {
            // your code here
            return helper(root, NULL);
        }

    