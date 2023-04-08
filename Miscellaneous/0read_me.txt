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


