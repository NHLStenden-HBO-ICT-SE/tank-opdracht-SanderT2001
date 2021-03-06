#pragma once

namespace St
{
    class GridAddTankCommand : public GridChangeCommand
    {
        public:
            GridAddTankCommand(Tank* tank);
            virtual void execute(Grid* grid);

        private:
            Tank* tank;
    };
};
