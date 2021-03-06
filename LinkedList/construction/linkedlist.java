public class linkedlist{
    private class Node{
        private int data = 0;
        private Node next = null;

        Node(int data){
            this.data = data;
        }
    }

    private Node head = null;
    private Node tail = null;
    private int NoOfNodes = 0;
    
    public int size(){
        return this.NoOfNodes;
    }
    
    public boolean isEmpty(){
        return size()==0;
    }

    //=======================================================================

    protected handleZeroSize(Node node){
        this.head = node;
        this.tail = node;
    }

    protected void addFirstNode(Node node){
        if(size()==0){
            handleZeroSize(node);
        }else{
            node.next = this.head;
            this.head = node;
        }

        this.NoOfNodes++;
    }

    public void addFirst(int data){
        Node node = new Node(data);
        addFirstNode(node);
    }

    //=======================================================================

    protected void addLastNode(Node node){
        if(size()==0){
            handleZeroSize(node);
        }else{
            this.tail.next = node;
            this.tail = node;
        }
        this.NoOfNodes++;
    }

    public void addLast(int data){
        Node node = new Node(data);
        addLastNode(node);
    }

    //========================================================================

    protected void handelSize1() {
        this.head = null;
        this.tail = null;
    }

    protected Node removeFirsNode(){
        Node temp = head;
        if(size()==1){
            handleSize1();
        }else{
            this.head = this.head.next;
        }
        temp.next = null;
        this.NoOfNodes--;
        return temp;
    }

    public int removeFirst() throws Exception{
        if(size()==0){
            throw new Exception("Linked List is Empty");
        }
        Node node = removeFirstNode();
        return node.data;
    }

    //======================================================================

    protected Node getNodeAt(int idx){
        Node temp = this.head;
        while(idx-- > 0){
            temp = temp.next; 
        }
        return temp;
    }

    //======================================================================

    protected Node removeLastNode(){
        Node temp = tail;
        if (size() == 1)
            handleSize1();
        else {
            Node secondLastNode = getNodeAt(size() - 2);
            secondLastNode.next = null;
            this.tail = secondLastNode;
        }

        this.NumberOfNodes--;
        return temp;
    }

    public int removeLast() throws Exception{
        if(size()==0){
            throw new Exception("LinkedList is empty");
        }
        Node node = removeLastNode();
        return node.data;
    }

    //=========================================================================

    protected void addNodeAt(Node node, int idx) {
        if (idx == 0)
            addFirstNode(node);
        else if (idx == size())
            addLastNode(node);
        else {
            Node nodeAt = getNodeAt(idx - 1);
            Node forw = nodeAt.next;

            nodeAt.next = node;
            node.next = forw;
            this.NumberOfNodes++;
        }
    }

    public void addAt(int idx,int data) throws Exception{
        if(idx<0 || idx > size()){
            throw new Exception("Invalid index");
        }
        Node node = new Node(data);
        addNodeAt(node, idx);
    }

    // ==============================================

    public int getFirst() throws Exception {
        if (size() == 0)
            throw new Exception("LinkedList is Empty");

        return this.head.data;

    }

    public int getLast() throws Exception {
        if (size() == 0)
            throw new Exception("LinkedList is Empty");
        return this.tail.data;
    }

    public int getAt(int idx) throws Exception {
        if (size() == 0)
            throw new Exception("LinkedList Is Empty");
        else if (idx < 0 || idx >= size())
            throw new Exception("Invalid Index");

        return getNodeAt(idx).data;
    }

    //=====================================================

    protected Node removeNodeAt(int idx){
        if (idx == 0)
            return removeFirstNode();
        else if (idx == size() - 1)
            return removeLastNode();
        else{
            Node prevNode = getNodeAt(idx - 1);
            Node removeNode = prevNode.next;
            Node forwardNode = removeNode.next;

            prevNode.next = forwardNode;
            removeNode.next = null;

            this.NumberOfNodes--;
            return removeNode;
        }
    }
    public int removeAt(int idx)throws Exception{
        if (size() == 0)
            throw new Exception("LinkedList Is Empty");
        else if (idx < 0 || idx >= size())
            throw new Exception("Invalid Index");

        Node node = removeNodeAt(idx);
        return node.data;
    }




}