#ifndef PONDERED_GRAPH_MATRIX_H
# define PONDERED_GRAPH_MATRIX_H

#define DEFAULT_VALUE 3.40282347e+38F

class PonderedGraphMatrix {
    public:
        PonderedGraphMatrix(int);
        ~PonderedGraphMatrix(void);
        int countEdges(void) const;
        void insertEdge(int, int, float);
        void deleteEdge(int, int);
        bool edgeExists(int, int) const;
        bool hasAdjacent(int) const;
        int degree(int) const;
        PonderedGraphMatrix mst(void);
        float getCost(void) const;
        void setCost(float);

    protected:
        int _n;
        int _edges;
        float **_matrix;
        float _cost;

        bool isValidVertex(int) const;
};

#endif