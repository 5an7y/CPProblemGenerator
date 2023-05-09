#pragma once

#include <stdexcept>

namespace Background {

    template<typename T>
    class ST_checker {
        public:
            struct STNode
            {
                T l, r;
                uint64_t tam;
                STNode *l_node, *r_node;

                STNode(T l_, T r_) {
                    l = l_;
                    r = r_;
                    l_node = r_node = NULL;
                    tam = r - l + 1;
                }

                ~STNode() {
                    if (l_node) delete l_node;
                    if (r_node) delete r_node;
                }
            };

            STNode *root;
        
            ST_checker(T l, T r) {
                if (l > r)
                    throw std::invalid_argument("In ST checker l should be less or equal than r");
                root = new STNode(l, r);
            }

            T get_k(uint64_t k) {
                return _get_k(k, root);
            }

            void remove_k (uint64_t k) {
                _remove_k(k, root);
            } 
            
            T pop_k(uint64_t k) {
                T val = _get_k(k, root);
                _remove_k(k, root);
                return val;
            }

            T _get_k(uint64_t k, STNode* node) {
                if (node -> l == node -> r)
                    return node -> l;
                
                T mit = (node->l + node->r) / 2;
                if ( !(node -> l_node) )
                    node -> l_node = new STNode(node -> l, mit);
                if ( !(node -> r_node) )
                    node -> r_node = new STNode(mit +  1, node -> r);
                
                uint64_t l_sz = node -> l_node -> tam;

                if (k <= l_sz) return _get_k(k, node -> l_node); 
                return _get_k(k - l_sz, node -> r_node);
            }

            void _remove_k(uint64_t k, STNode* node) {
                node -> tam -= 1;

                if (node -> l == node -> r)
                    return;
                
                T mit = (node->l + node->r) / 2;
                if ( !(node -> l_node) )
                    node -> l_node = new STNode(node -> l, mit);
                if ( !(node -> r_node) )
                    node -> r_node = new STNode(mit +  1, node -> r);
                
                uint64_t l_sz = node -> l_node -> tam;

                if (k <= l_sz) _remove_k(k, node -> l_node); 
                else _remove_k(k - l_sz, node -> r_node);
                return;
            }
            
    };
}