#pragma once

struct MapPosition {
	int x;
	int y;

	/// <summary>
	/// Genera una posicion aleatoria para cualquier objeto que posea un MapPosition
	/// </summary>
	void RandPosition();
};