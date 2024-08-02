# This script is to generate images and animations for binary tree demonstrations.
# If you want to run this, you should have manim installed.
# https://docs.manim.community/

from manim import *

class WorstBinaryTreeShape(Scene):
    def construct(self):
        vertices = [1, 2, 3, 4, 5]
        edges = [(1, 2), (2, 3), (3, 4), (4, 5)]
        graph = Graph(vertices,
                      edges,
                      vertex_config={
                        'radius': 0.30,
                        'fill_color': ManimColor("#808080")
                      },
                      edge_config={'stroke_color': ManimColor("#808080")},
                      layout_scale=2,
                      layout="tree",
                      root_vertex=1,
                    )
        graph.scale(1.5)
        self.add(graph)
