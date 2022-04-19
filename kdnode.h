#pragma once

namespace St
{
    class KDNode
    {
        public:
            KDNode();
            float getValue() { return this->value; }
            void setValue(float value) { this->value = value; }

            Tank* getTank() { return this->tank; }
            Tank* setTank(Tank* value) { this->tank = value; }

            bool hasLeftNode() { return (this->left != NULL); }
            bool hasRightNode() { return (this->right != NULL); }

            KDNode* getLeftNode() {
                if (this->left == NULL) {
                    this->left = new KDNode();
                }

                return this->left;
            }

            KDNode* getRightNode() {
                if (this->right == NULL) {
                    this->right = new KDNode();
                }

                return this->right;
            }

        private:
            float value = 0;
            Tank* tank = NULL;

            KDNode* left = NULL;
            KDNode* right = NULL;
    };
};
