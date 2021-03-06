#pragma once

namespace St
{
    class GridRemoveTankCommand : public GridChangeCommand
    {
        public:
            GridRemoveTankCommand(Tank* tank);
            virtual void execute(Grid* grid);

        private:
            Tank* tank;
    };
};
