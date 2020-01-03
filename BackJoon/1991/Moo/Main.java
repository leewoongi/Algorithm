package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node {
	char data;
	Node left;
	Node right;

	public Node(char data) {
		this.data = data;
	}
}

class Tree {
	public Node root;

	public Tree(char data, char left, char right) {
		// root = new Node(data);

		if (data != '.') // .이 아니면 노드 생성 후 데이터 삽입
			root = new Node(data);
		if (left != '.') // . 이 아니면 노드 생성후 좌측에 삽입
			root.left = new Node(left);
		if (right != '.') // .이 아니면 노드 생성후 우측에 삽입
			root.right = new Node(right);
	}

	/*
	 * public void setRoot(Node node) { this.root = node; }
	 * 
	 * public Node getRoot() { return root; }
	 */

	public void add(char data, char left, char right) {
		next(root.left, data, left, right);
		next(root.right, data, left, right);
	}

	public void next(Node node, char data, char left, char right) {
		if (node == null) // 노드가 null이면 종료.
			return;

		// .이 아니면 왼쪽노드 오른쪽노드 생성후 데이터 삽입
		else if (node.data == data) {
			if (left != '.')
				node.left = new Node(left);
			if (right != '.')
				node.right = new Node(right);
			// 탐색할 노드들이 남아있는 경우
		} else {
			next(node.left, data, left, right); // 왼쪽 탐색
			next(node.right, data, left, right); // 오른쪽 탐색
		}
	}

	/*
	 * public Node makeTree(Node left, char data, Node right) { Node node = new
	 * Node(); node.data = data; node.left = left; node.right = right; return node;
	 * }
	 */

	public void preorder(Node node) { // 전위순회:루트 -> 왼쪽자식 -> 오른쪽자식
		if (node != null) {
			System.out.print(node.data);
			if (node.left != null) {
				preorder(node.left);
			}
			if (node.right != null) {
				preorder(node.right);
			}

		}
	}

	public void inorder(Node node) { // 중위순회: 왼쪽자식 -> 루트 -> 오른쪽 자식
		if (node != null) {
			if (node.left != null) {
				inorder(node.left);
			}
			System.out.print(node.data);
			if (node.right != null) {
				inorder(node.right);
			}

		}
	}

	public void postorder(Node node) { // 후위순회 : 왼쪽자식 -> 오른쪽자식 -> 루트
		if (node != null) {
			if (node.left != null) {
				postorder(node.left);
			}
			if (node.right != null) {
				postorder(node.right);
			}
			System.out.print(node.data);

		}
	}
}

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		// replaceAll(" ", "")의 쓰임은 readLine으로 읽어들인 문자열에서 띄어쓰기를 제거하고 toCharArray()로 문자
		// 하나 하나를 char형 으로 처리
		char[] data = in.readLine().replaceAll(" ", "").toCharArray();

		Tree t = new Tree(data[0], data[1], data[2]);

		for (int i = 1; i < n; i++) {
			data = in.readLine().replaceAll(" ", "").toCharArray();
			t.add(data[0], data[1], data[2]);
		}

		t.preorder(t.root);
		System.out.println();
		t.inorder(t.root);
		System.out.println();
		t.postorder(t.root);

		/*
		 * for(int i = 0; i<=n; i++) { String words = sc.nextLine(); }
		 */

	}
}

