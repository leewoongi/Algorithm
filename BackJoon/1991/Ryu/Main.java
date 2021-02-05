import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class node{
	node left;
	node right;
	char val;
	public node(char val) {
		this.val = val;
	}
}

class tree{
	node root;
	public void search(node root, char val, char left, char right) {
		if(root == null)
			return;
		else if(root.val == val) {
			if(left != '.')
				root.left = new node(left);
			if(right != '.')
				root.right = new node(right);
		}
		else {
			search(root.left,val,left,right);
			search(root.right,val,left,right);
		}
	}
	public void add(char val, char left, char right) {
		if(root == null){
			if(val != '.')
				root = new node(val);
			if(left !='.')
				root.left = new node(left);
			if(right != '.')
				root.right = new node(right);
		}
		else {
			search(root,val,left,right);
		}
	}
	public void preorder(node root) {
		System.out.print(root.val);
		if(root.left != null)
			preorder(root.left);
		if(root.right != null)
			preorder(root.right);
	}
	public void inorder(node root) {
		if(root.left != null)
			inorder(root.left);
		System.out.print(root.val);
		if(root.right != null)
			inorder(root.right);
	}
	public void postorder(node root) {
		if(root.left != null)
			postorder(root.left);
		if(root.right != null)
			postorder(root.right);
		System.out.print(root.val);
	}
}

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());;
		char arr[];
		tree t1 = new tree();
		
		for(int i = 0; i<a; i++) {
			arr = in.readLine().replaceAll(" ","").toCharArray();
			t1.add(arr[0], arr[1], arr[2]);
		}
		t1.preorder(t1.root);
		System.out.println();
		t1.inorder(t1.root);
		System.out.println();
		t1.postorder(t1.root);
	}
}
