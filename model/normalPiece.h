#include <iostream>
#include "piece.h"

#pragma once

namespace draughts
{
    namespace model
    {
			class normalPiece : public piece
			{
				public:
					virtual override void move(int sX,int sY,int eX,int eY)
					{
						
					}
					
					virtual override char draw(int sX,int sY)
					{
						
					}
			};
	}
	
}
