To compute search time complexity of a binary search tree (BST) we need to define a few things first.

Every node on the tree has a path, which is the number of previous nodes visited before getting into that node. The path length is defined as the amount of nodes previous visited. For example, the root node has a path length of zero since no node is previous visited. The nodes immediately after the root have a path length of 1 and so on.

Besides the path, we can define a level and height for every node on the tree.

A level is defined as being the path length plus one. For example, the root node has level 1 since its path length is zero. The nodes immediately after the root have level 2 since their path length is 1 and so on.
Height, in turn, is defined as being the highest level on the tree.

To calculate the average cost of finding a node in the BST we should sum all path lengths of all nodes and divide it by the number of nodes. This is given by the following formulas:

$$
IPL = \sum_{i=1}^{h}f(i)\cdot(i-1)
$$

$$
APL = \frac{IPL}{n}
$$

where $i$ represents the level that will iterate from the root to the height ($h$). The function $f(i)$ is what will calculate the number of nodes in that level and $(i-1)$ is the path length of current level. IPL is the sum of length of all nodes (IPL stands for internal path length) and APL is the average (APL stands for average path length).

When we are talking about an incomplete binary tree (when the number of leaves in the tree is not a power of 2), the worst shape it can have is exactly the same as a linked list. On this scenario, the time complexity to find a certain node is $\mathbb{O}(n)$.

To demonstrate this, let's see how this kind of tree looks like.

<p align="center">
    <img
        src="media/images/binary-tree-shapes/WorstBinaryTreeShape_ManimCE_v0.18.1.png"
        alt="binary tree structured as a linked list" height="200"
    />
</p>

It is noticeable that each level has only one node, so, our $f(i)$ will always be:

$$
f(i) = 1
$$

Another thing that we can notice is that the heigth of the tree is equal to the number of nodes, so:

$$
h = n
$$

where $n$ is the number of nodes.

With all that information in hands we can calculate the average.

$$
IPL = \sum_{i=1}^{n}1(i-1) = \frac{(0+n-1)n}{2} = \frac{(n-1)n}{2}
$$

$$
APL = \frac{IPL}{n} = \frac{\frac{(n-1)n}{2}}{n} = \frac{(n-1)n}{2n} = \frac{n-1}{2}
$$

$$
APL = \frac{n-1}{2}
$$

which is $\mathbb{O}(n)$ as we wanted to prove.

(If you want to see a more mathematical approach of how big $\mathbb{O}$ notation works and you speak portuguese, checkout [this video](https://www.youtube.com/watch?v=miLF-hDeNzU) made by some guy that turns out to have the same as me)