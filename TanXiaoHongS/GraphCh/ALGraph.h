#pragma once
#include "stdafx.h"
#include "Queue.h"
#include "Stack.h"
#include "SeqList.h"
//���ڽӱ�洢��Graph�� ����

//�����������飬������SeqList
typedef struct VertexType {
	//SeqList<int> VertexType;
	int *VertexType; //����
}VertexType;

//���ڽӾ���洢��Graph�� ����
#define INFINITY std::numeric_limits<int>::max() //�������ֵ
#define MAX_VERTRIX_NUM 20 //�������ֵ
typedef enum { DG, DN, AG, AN } GraphKind;//ͼ������
//DGΪ����ͼ��DNΪ������
//AGΪ����ͼ��ANΪ������

//���ڽӾ���洢��Graph�� //��߻���㵥Ԫ�Ľṹ //��ʾ�ڽӱ�ı߽��
template <typename T, typename VRType, typename InfoType>
class ArcCell {
public:
	VRType adj; //�����ϵ����
	// ͼ���б�����Ϊ1,�ޱ�����Ϊ0 ��������int
				//�����б�Ȩֵ���ޱ������
	InfoType* info;//����� //ָ��û������Ϣָ�� �������ö�����Ϣ����type[] *
};

//���ڽӱ�洢��Graph������ �ͻ���ص���Ϣ��Ա�ṹ//����Ȩֵ
typedef struct InfoType {
	int cost; //����Ȩֵ
}InfoType;
//���ڽӱ�洢��Graph�࣬���߽�������������� ����
typedef struct ArcNode {
	int adjvex; //�û���ָ�����������е�λ�ã��±꣩ data domain 1
	struct ArcNode* nextarc; //ָ����һ���� ��һ���ڽӵ� ref domain
	InfoType* info; //�ͻ���ص���Ϣ //����Ȩֵ data domain 2
}ArcNode;
//������Ϣ �������飬ͷ������� ��㶨��
typedef struct VNode {
	VertexType data;  //������Ϣ//�����������飬������SeqList��data domain
	ArcNode* firstarc; //ָ����һ���ڽӵ� ref domain
}VNode, AdjList[MAX_VERTRIX_NUM];//������Ϣ��������

//���ڽӱ�洢��Graph�� ����
template<typename T>
class ALGraph {
public:
	AdjList vertices; //ͷ�������
	int vexnum; //������
	int arcnum; //����
	int kind; //��������

	 //�����ڽӾ����ʾ����������ͼ,���췽��
	bool CreateN(MGraph<T> &G) {
		//��ʼ���ڽӱ� ͷ����, ����Ԫ���ֶ����룬�������������������Ϣ��Ȩֵ��
		scanf(&G.vexnum, &G.arcnum, &IncInfor);//�������ͱ���
		for (int i = 0; i < &G.vexnum; ++i) {
			scanf(&G.vertices[i].data);//����������
			G.vertices[i].firstarc = NULL; //�������ÿ�
		}
		//���뻡�����ڽӱ� ��߽��� ��ֵ
		for (int k = 0; k < G.arcnum; ++k) {
			//����Ԫ���ֶ����룬����1ֵ������2ֵ��Ȩֵ
			scanf(&v1, &v2, &w);
			int i = LocateVex(G, v1); //Ѱ�ҽ��1λ��
			int j = LocateVex(G, v2); //Ѱ�ҽ��2λ��
									  //2���㹹��һ����
			p = new ArcNode(); //�����µı���
			p.adjvex = j; //��������� Ϊ v2
			p.nextarc = G.vertics.firstarc; //��ͷ�������ͷ���������һ������ step1
			G.vertics.firstarc;  //��ͷ�������ͷ���������һ������ step2
			if (IncInfo) Input(*p.info); //����Ȩֵ
		}
		return true;
	}//!_bool CreateN()
	 //class ALGraph {
	 //public:
	 //
	 //	ALGraph() {}
	 //
	 //	virtual ~ALGraph() {}
	 //};

	 //������ȱ���
	bool visited[MAX_VERTRIX_NUM]; //����״̬��
	bool(*VisitFunc)(int v);  //ί�У����ʽ��	
							  //������ȱ���
	void DFSTraverse(ALGraph G, bool(*Visit(int v))) { //������ȱ��� Tan
		VisitFunc = Visit; //ί�У����ʽ��;ί�и�ֵ ���ʺ���
		for (int v = 0; v < G.vexnum; ++v)  //��ʼ�� ����״̬��
			visited[v] = false;
		for (int v = 0; v < G.vexnum; ++v) { //���� �ӵ�һ�������һ���ڽӵ�
			if (!visited[v]) DFS(G, v);//������ȱ����㷨 ���� �ݹ����
		}
	}
	void DFS(ALGraph G, int v) { //������ȱ����㷨 ���� �ݹ����
		visited[v] = true; //����״̬�����
		VisitFunc(v); //ί�е���
					  //�ҵ���һ���ڽӵ㣬wΪtrue,����һ���ڽӵ�
		for (int w = FirstAdjVex(G��v); w; w = NextAdjVex(G, v, w))
			if (!visited[w]) DFS(G, w); //������ȱ����㷨 ���� �ݹ����
	}

	//������ȱ��� Tan ��α������ƹ�
	void BFSTravese(ALGraph G, bool(*Visit(int v))) {
		for (int v = 0; v < G.vexnum; ++v)  //��ʼ�� ����״̬��
			visited[v] = false;
		InitQueue(Q); //new ����
		for (int v = 0; v < G.vexnum; ++v)
			if (!visited[v]) { //��鵽δ���ʣ��ݹ����
				visited[v] = true; //����״̬�����
				Visit(v); //���ʽ��
				EnQueue(Q, u); //���
				while (!QueueEmpty(Q)) { //���� �ǿ�
					DeQueue(Q, u); //����
					//�ҵ���һ���ڽӵ㣬wΪtrue,����һ���ڽӵ�
					for (int w = FirstAdjVex(G��v); w; w = NextAdjVex(G, v, w))
						if (!visited[w]) {
							visited[w] = true; //����״̬�����
							Visit(w); //���ʽ��
							EnQueue(Q, w); //���
						}//!_if
				}//!_while
			}//!_if
	}//!_BFSTravese

	 //���ڽӱ�洢��Graph�� �������Ľṹ
	template<typename T>
	class Vertex {
		friend class Graph<T>;//��Ԫ��
	public:
		T VerName; //��������� 	data domain ,store node value
		Edge* adjacent; //�������ͷָ�� ref domain
	};

	//���ڽӱ�洢��Graph�� �߱���Ľṹ
	template<typename T>
	class Edge {
		friend class Graph<T>;//��Ԫ��
	public:
		int VerAdj; //���ڽӶ������	data domain 1
		int cost;	//�˱ߵ�Ȩֵ	data domain 2	
		Edge<T>* link; //ָ����һ���߽���ָ�� ref domain
					   //���캯��
		Edge(int d, int c) : VerAdj(d), cost(c), link(NULL) {}
	};

	//���������㷨,�����ǰ��������
	//���壺������ͼ�еĶ��������Է�ʽ�������򡣼������κ������Զ���u������v�������uv���������������У�����u�����ڶ���v��ǰ�档
	//	������������Գ���Ļ�����ô��������һ���ǳ��ǳ���������ӡ���ѡ�Ρ������κο������ݽṹ����鼮��ͬѧ��֪�����ɡ������ҷǳ���ѧϰһ�Ż���ѧϰ�Ŀγ̣�����������ô�γ�֮ǰ�����Ǳ���ҪѧϰһЩ�����γ̣�����������ѧ���ۣ�C���Գ�����ƣ����ݽṹ���㷨�ȵȡ���ô����ƶ�ѡ�޿γ�˳��Ĺ��̣�ʵ���Ͼ���һ����������Ĺ��̣�ÿ�ſγ��൱������ͼ�е�һ�����㣬�����Ӷ���֮�������߾��ǿγ�ѧϰ���Ⱥ��ϵ��ֻ����������̲�����ô���ӣ��Ӷ�����Ȼ�������ǵĴ���������ˡ�������������㷨����ʽ���������Ľ����������������
	//	��ô�ǲ������е�����ͼ���ܹ������������أ���Ȼ���ǡ�����������������ӣ������������ѡ�޼������ѧ�������ſ�֮ǰ��Ҫ����ѧϰ����ѧϰ�����ǲ��ǻᱻŪ��Ϳ������������£����޷���������������Ϊ���м���ڻ��������Ĺ�ϵ���Ӷ��޷�ȷ��˭��˭��������ͼ�У��������������Ϊ���ڻ�·����ˣ�һ������ͼ�ܱ���������ĳ�Ҫ������������һ�������޻�ͼ(DAG��Directed Acyclic Graph)��
	/*���ѿ������㷨��ʵ��ʮ��ֱ�ۣ��ؼ�������Ҫά��һ�����Ϊ0�Ķ���ļ��ϣ�
		ÿ�δӸü�����ȡ��(û�������ȡ���������ȡ��Ҳ�У�ʹ�ö��� / ջҲ�У���ͬ)һ�����㣬���ö�����뱣������List�С�
		������ѭ�������ɸö������������бߣ���ͼ���Ƴ������ߣ�ͬʱ��ȡ�ñߵ�����һ�����㣬����ö��������ڼ�ȥ������֮��Ϊ0����ôҲ���������ŵ����Ϊ0�ļ����С�Ȼ������Ӽ�����ȡ��һ�����㡭������

		������Ϊ��֮�󣬼��ͼ���Ƿ񻹴����καߣ�������ڵĻ���˵��ͼ�����ٴ���һ����·�������ڵĻ��򷵻ؽ��List����List�е�˳����Ƕ�ͼ������������Ľ����*/
	public class KahnTopological {
		private List<Integer> result;   // �����洢�����  
		private Queue<Integer> setOfZeroIndegree;  // �����洢���Ϊ0�Ķ���  
		private int[] indegrees;  // ��¼ÿ�����㵱ǰ�����  
		private int edges;
		private Digraph di;

		public KahnTopological(Digraph di) {
			this.di = di;
			this.edges = di.getE();
			this.indegrees = new int[di.getV()];
			this.result = new ArrayList<Integer>();
			this.setOfZeroIndegree = new LinkedList<Integer>();

			// �����Ϊ0�ļ��Ͻ��г�ʼ��  
			Iterable<Integer>[] adjs = di.getAdj();
			for (int i = 0; i < adjs.length; i++) {
				// ��ÿһ���� v -> w   
				for (int w : adjs[i]) {
					indegrees[w]++;
				}
			}

			for (int i = 0; i < indegrees.length; i++) {
				if (0 == indegrees[i]) {
					setOfZeroIndegree.enqueue(i);
				}
			}
			process();
		}

		private void process() {
			while (!setOfZeroIndegree.isEmpty()) {
				int v = setOfZeroIndegree.dequeue();

				// ����ǰ������ӵ��������  
				result.add(v);

				// ������v���������б�  
				for (int w : di.adj(v)) {
					// ���ñߴ�ͼ���Ƴ���ͨ�����ٱߵ���������ʾ  
					edges--;
					if (0 == --indegrees[w])   // ������Ϊ0����ô�������Ϊ0�ļ���  
					{
						setOfZeroIndegree.enqueue(w);
					}
				}
			}
			// �����ʱͼ�л����ڱߣ���ô˵��ͼ�к��л�·  
			if (0 != edges) {
				throw new IllegalArgumentException("Has Cycle !");
			}
		}

		public Iterable<Integer> getResult() {
			return result;
		}
	}

	#define length 10;
	//���������㷨
	TopoOrder() {
		int* count = new int[length]; //new ���������� ��̬����ջ ˳��ջ array 
		int top = -1; //��ջ
		for (int i = 0; i < length; i++) //��ʼ����ȱ�˳��ջ
			if (count[i] == 0) {  //�ҵ����Ϊ0�Ķ��� Ȼ����ջ
				count[i] = top; //�����Ϊ0�Ķ���ѹ��ջ��//��valueΪtopֵ����ջ,��value�ɱ�ʾջ����һ�����Ϊ0��Ԫ�ص�index�±�
				top = i;  //top ��Ϊi count,top++
			}
		Vertex<T>* head = new Vertex<T>[length];//new ���������
		for (int i = 0; i < length; i++)
			if (top == -1) { //û�����Ϊ0�Ķ��㣬���л�·
				cout << "There is a cycle in network !" << endl; return;
			} else { //û�л�·
				int j = top; //��ջtop��j��top��Ԫ�����
				top = count[top]; //top--��ȡ���α꣬count[top]����һ���α�
				cout << j << endl; //��� ��ջ�Ķ���Ԫ��ֵ�����滻������� 
				Edge<T>* p = head[j].Adjacent; //�õ�j����һ���ڽӵ������
				while (p != NULL) { //�ǿ�
					int k = p->VerAdj; //�õ��ڽӵ�����
					if (--count[k] == 0) { //��������,����ִ�д���ŵ�ÿ���ڽӵ�����-1��ifΪ0
						count[k] = top; //��ջ ��̬����ջ �����α� �α�ʵ�ַ�
						top = k; //top++��cursor switch,�α���ת���α���Ϊ��ǰԪ��
					}
					p = p->link; //ptr ++ ��һ��������
				}
			}//!_for (int i = 0; i < length; i++) 
	}//!_TopoOrder

	//�������ͼ���������е��㷨
	//1ѡ�����Ϊ0�Ķ�������������ǳ�ջ�������
	//2��ͼ��ɾ���ý��������Ըý��Ϊβ�Ļ������ڽӵ��ÿ���߽������-1,���-1�Ժ���0,����ջ
	//3�ظ��������������������ȫ�����㣬���ͼ�в����ڻ���������ڻ�
	//�㷨ʵ�֣�
	/*���ڽӱ�ķ����洢����ͼ��
	ͷ���������Ϣ���������;
	����һ��ջ����У����ڴ�����Ϊ0�Ķ��㡣*/
	int* indegree = new int[length]; //�������
	bool TopologicalSort(ALGraph G) {
		FindInDegree(G, indegree); //�������0,�����������
		Stack<T> S = new Stack<T>; //��ʼ��ջ
		for (int i = 0; i < G.vexnum; ++i) if (!indegree[i]) S.Push(S, i); //�����0,��ջ
		int count = 0; //������
		while (!S.IsEmpty()) {
			S.Pop(S, i); printf(i, G.vertices[i].data); ++count; //��ջ
			for (p = G.vertices[i].firstarc; p; p = p->nextarc) { //ɾ����
				k = p->adjvex;
				if (!(--indegree[k])) S.Push(S, k); //�����0,��ջ
			}
		}
		if (count < G.vexnum) return false; //˵���л�·
		else return true;
	}
	FindInDegree(ALGraph G, indegree) { //�������0,�����������
		int* count = new int[length]; //new ���������� ��̬����ջ ˳��ջ array 
		int top = -1; //��ջ
		for (int i = 0; i < length; i++) //��ʼ����ȱ�˳��ջ
			if (count[i] == 0) {  //�ҵ����Ϊ0�Ķ��� Ȼ����ջ
				count[i] = top; //�����Ϊ0�Ķ���ѹ��ջ��//��valueΪtopֵ����ջ,��value�ɱ�ʾջ����һ�����Ϊ0��Ԫ�ص�index�±�
				top = i;  //top ��Ϊi count,top++
			}
	}

	/*4.Dijkstra�㷨(Dijkstra's algorithm)

�Ͻ�˹�����㷨��Dijkstra��s algorithm�����ɺ����������ѧ�Ұ��Ⱥն����Ͻ�˹����������Ͻ�˹�����㷨ʹ���˹��������������Ǹ�Ȩ����ͼ�ĵ�Դ���·�����⣬�㷨���յõ�һ�����·���������㷨������·���㷨������Ϊ����ͼ�㷨��һ����ģ�顣

���㷨�����������һ����Ȩ�ص�����ͼ G���Լ�G�е�һ����Դ���� S�������� V ��ʾ G �����ж���ļ��ϡ�ÿһ��ͼ�еıߣ����������������γɵ�����Ԫ�ضԡ�(u, v) ��ʾ�Ӷ��� u �� v ��·�������������� E ��ʾG�����бߵļ��ϣ����ߵ�Ȩ������Ȩ�غ��� w : E ��[0, ��] ���塣��ˣ�w(u, v) ���ǴӶ��� u ������ v �ķǸ�Ȩ�أ�weight�����ߵ�Ȩ�ؿ����������������֮��ľ��롣�������·����Ȩ�أ����Ǹ�·�������бߵ�Ȩ���ܺ͡���֪�� V ���ж��� s �� t��Dijkstra �㷨�����ҵ� s �� t�����Ȩ��·��(���磬���·��)������㷨Ҳ������һ��ͼ�У��ҵ���һ������ s ���κ�������������·�������ڲ�����Ȩ������ͼ��Dijkstra �㷨��Ŀǰ��֪�����ĵ�Դ���·���㷨��

�㷨���裺

1.  ��ʼʱ�� S = { V0 }, T = { ���ඥ�� }��T�ж����Ӧ�ľ���ֵ

������<V0, Vi>��d(V0, Vi)Ϊ<V0, Vi>���ϵ�Ȩֵ

��������<V0, Vi>��d(V0, Vi)Ϊ��

2.  ��T��ѡȡһ�������ֵΪ��С�Ķ���W�Ҳ���S�У�����S

3.  ������T�ж���ľ���ֵ�����޸ģ����ӽ�W���м䶥�㣬�� V0 �� Vi �ľ���ֵ���̣����޸Ĵ˾���ֵ

�ظ���������2��3��ֱ��S�а������ж��㣬��W = Vi Ϊֹ*/



};//!_bool CreateN(MGraph<T> &G)

