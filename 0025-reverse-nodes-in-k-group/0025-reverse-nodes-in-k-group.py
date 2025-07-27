class Solution:
    def findKthNode(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        while head != None and k > 1:
            head = head.next
            k = k - 1
        return head
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        prev = None

        while curr != None:
            nextEl = curr.next
            curr.next = prev
            prev = curr
            curr = nextEl
        
        return prev

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        temp = head
        prevEle = None
        newHead = None

        while temp != None:
            kthElement = self.findKthNode(temp, k)
            
            if kthElement == None:
                if prevEle:
                    prevEle.next = temp
                break
            
            nextEle = kthElement.next
            kthElement.next = None
            
            reverseHead = self.reverseList(temp)
            
            if temp == head:
                newHead = reverseHead
            
            if prevEle:
                prevEle.next = reverseHead
            
            prevEle = temp
            temp = nextEle
        
        return newHead if newHead else head
