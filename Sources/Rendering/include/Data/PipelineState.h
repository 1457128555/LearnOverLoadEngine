#pragma once

#include <bitset>

namespace Rendering
{ 
	struct PipelineState
	{
		PipelineState();

		union 
		{
			struct
			{


			
			};

			std::bitset<64> bits;
			uint8_t bytes[8];
		};
	};	
}

