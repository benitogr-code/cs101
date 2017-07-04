#pragma once

namespace CS101
{
	template<typename T>
	struct SGraphNode
	{
		enum class EState
		{
			NotVisited,
			Traversing,
			Visited
		};

		typedef std::set<SGraphNode<T>*> Edges;

		SGraphNode(const T& value)
			: data(value)
			, state(EState::NotVisited)
		{
		}

		bool operator < (const SGraphNode<T>& rhs) const
		{
			return data < rhs.data;
		}

		T      data;
		EState state;
		Edges  edges;
	};

	template<typename T>
	class CGraph
	{
	public:
		typedef typename std::set< SGraphNode<T> > Nodes;
	
	public:
		void AddNode(const T& node)
		{
			m_nodes.insert(SGraphNode<T>(node));
		}

		void RemoveNode(const T& node)
		{
			m_nodes.erase(SGraphNode<T>(node));
		}

		void Connect(const T& node1, const T& node2)
		{
			typename Nodes::iterator itNode1 = m_nodes.find(SGraphNode<T>(node1));
			typename Nodes::iterator itNode2 = m_nodes.find(SGraphNode<T>(node2));

			if ((itNode1 == m_nodes.end()) || (itNode2 == m_nodes.end()))
				return;

			SGraphNode<T>& ref = const_cast<SGraphNode<T>&>(*itNode2);
			typename SGraphNode<T>::Edges& n1Edges = const_cast<typename SGraphNode<T>::Edges&>(itNode1->edges);
			n1Edges.insert(&(ref));
		}

		void VisitDFS(const std::function<void(const T&)>& visitFunction)
		{
			PrepareForSearch();
			VisitDFS(First(), visitFunction);
		}

		void VisitBFS(const std::function<void(const T&)>& visitFunction)
		{
			PrepareForSearch();
			VisitBFS(First(), visitFunction);
		}

	private:
		void VisitDFS(SGraphNode<T>* pNode, const std::function<void(const T&)>& visitFunction)
		{
			if (pNode == nullptr)
				return;

			visitFunction(pNode->data);
			pNode->state = SGraphNode<T>::EState::Visited;
			for (auto it = pNode->edges.begin(); it != pNode->edges.end(); ++it)
			{
				if ((*it)->state == SGraphNode<T>::EState::NotVisited)
					VisitDFS(*it, visitFunction);
			}
		}

		void VisitBFS(SGraphNode<T>* pNode, const std::function<void(const T&)>& visitFunction)
		{
			std::queue<SGraphNode<T>*> nodeQueue;
			nodeQueue.push(pNode);

			while (!nodeQueue.empty())
			{
				SGraphNode<T>* pCurrentNode = nodeQueue.front();
				nodeQueue.pop();

				visitFunction(pCurrentNode->data);
				pCurrentNode->state = SGraphNode<T>::EState::Visited;
				for (auto it = pCurrentNode->edges.begin(); it != pCurrentNode->edges.end(); ++it)
				{
					if ((*it)->state == SGraphNode<T>::EState::NotVisited)
					{
						(*it)->state = SGraphNode<T>::EState::Traversing;
						nodeQueue.push(*it);
					}
				}
			}
		}

		SGraphNode<T>* First() const
		{
			assert(!m_nodes.empty());
			return const_cast<SGraphNode<T>*>(&(*m_nodes.begin()));
		}

		void PrepareForSearch()
		{
			for (typename Nodes::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
			{
				const_cast<SGraphNode<T>&>(*it).state = SGraphNode<T>::EState::NotVisited;
			}
		}

	private:
		Nodes m_nodes;
	};
}
