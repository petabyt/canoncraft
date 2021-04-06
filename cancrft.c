#include <stdio.h>
#include <dryos.h>
#include <module.h>
#include <menu.h>
#include <config.h>
#include <bmp.h>
#include <console.h>
#include <math.h>

unsigned int texGrass[] = {
	0x76a559, 0x669b44, 0x78a354, 0x598a38, 0x6ca04a, 0x6da34d, 0x5d8d3c,
	0x619441, 0x5d8f3c, 0x679a46, 0x6ca24c, 0x639542, 0x84b261, 0x8db867,
	0x7da455, 0x69984a, 0x6fa152, 0x5e943a, 0x7ead58, 0x5c9037, 0x558b32,
	0x60963d, 0x6b9745, 0x5c8f38, 0x699642, 0x5c8e37, 0x6b9844, 0x75a34f,
	0x679c43, 0x73a04c, 0x729d4a, 0x6b9d4a, 0x6c9e4f, 0x6c9946, 0x7ca854,
	0x60953c, 0x6f9e49, 0x568932, 0x6d9a46, 0x709a47, 0x80ac58, 0x7fae58,
	0x699d45, 0x5c9038, 0x52872f, 0x4b8028, 0x558a32, 0x5f923f, 0x669648,
	0x679240, 0x5a8d37, 0x5e963c, 0x5b9037, 0x6c9946, 0x62963e, 0x5d9239,
	0x77a44f, 0x639740, 0x6e9c47, 0x719d4a, 0x5b8f37, 0x487e26, 0x4d832a,
	0x528332, 0x669648, 0x65913d, 0x598d35, 0x5e963c, 0x74a34e, 0x5b8e37,
	0x5a9137, 0x5c9339, 0x73a04c, 0x5e933b, 0x588c35, 0x62973e, 0x639a40,
	0x52872f, 0x76a44f, 0x75a854, 0x699a4b, 0x52882e, 0x568c33, 0x62983e,
	0x77a550, 0x639940, 0x548b32, 0x50862e, 0x568b32, 0x6b9643, 0x7aa853,
	0x5b9037, 0x5a9137, 0x538830, 0x74a14d, 0x71a44f, 0x619043, 0x538a30,
	0x5a9137, 0x51862e, 0x5f8a38, 0x63963f, 0x598f36, 0x669d43, 0x77a44f,
	0x77a24f, 0x63963e, 0x5c9339, 0x548b32, 0x558b32, 0x61963d, 0x6c9f4a,
	0x68994a, 0x51882e, 0x599037, 0x4f852d, 0x74a04d, 0x6e9946, 0x53872f,
	0x558b32, 0x6d9946, 0x598b35, 0x65923f, 0x5a8f37, 0x4d832a, 0x7dad56,
	0x679c43, 0x80ae5c, 0x74a756, 0x548b31, 0x5c9339, 0x548931, 0x7aa953,
	0x60933c, 0x52882f, 0x62983f, 0x7ba954, 0x5e923a, 0x7cac55, 0x679c43,
	0x447821, 0x6d9a46, 0x598c35, 0x679a46, 0x71a253, 0x73a04b, 0x6ca147,
	0x548b32, 0x4c8129, 0x5b9238, 0x5b9138, 0x74a24e, 0x78a551, 0x60963c,
	0x548930, 0x5c9339, 0x5e943a, 0x85b65e, 0x689e45, 0x83b35f, 0x68984a,
	0x719e4a, 0x79a551, 0x5e943b, 0x50862e, 0x588d34, 0x7aa853, 0x5e933b,
	0x548b31, 0x5f963c, 0x67a146, 0x5b9238, 0x598e36, 0x74a24e, 0x649941,
	0x5d8d3c, 0x659647, 0x5e943a, 0x77a44f, 0x679c43, 0x719f4a, 0x598c35,
	0x72a14c, 0x588c34, 0x599137, 0x6ba448, 0x599037, 0x4c8229, 0x50852d,
	0x649b41, 0x5b9138, 0x598b38, 0x669749, 0x51882e, 0x568b33, 0x5d933a,
	0x73a04c, 0x53862f, 0x5d9239, 0x5e943b, 0x588c34, 0x5f953c, 0x5b9138,
	0x50862e, 0x6a9643, 0x6ba046, 0x73a14d, 0x629341, 0x619042, 0x548b31,
	0x4b8129, 0x568c33, 0x538830, 0x558b32, 0x709e49, 0x6f9a47, 0x679140,
	0x77a650, 0x5c9138, 0x4f852d, 0x6c9946, 0x60923c, 0x6b9744, 0x679846,
	0x578639, 0x52882e, 0x548931, 0x598f36, 0x568c33, 0x5a9137, 0x639840,
	0x578b33, 0x51852e, 0x5c9239, 0x578d34, 0x4e832b, 0x4f832b, 0x709c49,
	0x61953c, 0x619440, 0x6f9d54, 0x5f943e, 0x81ad5c, 0x60903f, 0x609440,
	0x679b47, 0x6c9648, 0x78a254, 0x5d8d3c, 0x588b38, 0x629641, 0x609340,
	0x5d8f3c, 0x7ea859, 0x78a152, 0x77a758
};

unsigned int texDirt[] = {
	0x916848, 0x5f432d, 0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x916848,
	0x5f432d, 0x76553a, 0x5f432d, 0x5f432d, 0x76553a, 0x5f432d, 0x5f432d,
	0x76553a, 0x76553a, 0x76553a, 0x76553a, 0x5f432d, 0x555555, 0x5f432d,
	0x463020, 0x5f432d, 0x5f432d, 0x5f432d, 0x76553a, 0x76553a, 0x5f432d,
	0x463020, 0x76553a, 0x5f432d, 0x5f432d, 0x76553a, 0x463020, 0x5f432d,
	0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x916848, 0x5f432d, 0x463020,
	0x5f432d, 0x5f432d, 0x76553a, 0x5f432d, 0x463020, 0x916848, 0x5f432d,
	0x5f432d, 0x463020, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x916848,
	0x76553a, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x916848,
	0x76553a, 0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x463020, 0x5f432d,
	0x6a6a6a, 0x76553a, 0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x76553a,
	0x5b4535, 0x5f432d, 0x76553a, 0x916848, 0x76553a, 0x5f432d, 0x463020,
	0x76553a, 0x76553a, 0x5f432d, 0x76553a, 0x76553a, 0x463020, 0x5f432d,
	0x916848, 0x76553a, 0x5f432d, 0x463020, 0x5f432d, 0x76553a, 0x6a6a6a,
	0x5f432d, 0x5f432d, 0x5f432d, 0x463020, 0x5f432d, 0x5f432d, 0x5f432d,
	0x463020, 0x916848, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x6a6a6a,
	0x76553a, 0x463020, 0x5f432d, 0x916848, 0x5f432d, 0x463020, 0x916848,
	0x5f432d, 0x463020, 0x5f432d, 0x76553a, 0x76553a, 0x5f432d, 0x76553a,
	0x463020, 0x5f432d, 0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x76553a,
	0x463020, 0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x463020, 0x555555,
	0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x916848, 0x5f432d,
	0x76553a, 0x463020, 0x5f432d, 0x5f432d, 0x463020, 0x76553a, 0x5f432d,
	0x916848, 0x76553a, 0x5f432d, 0x463020, 0x916848, 0x76553a, 0x463020,
	0x76553a, 0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x916848, 0x76553a,
	0x76553a, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x916848, 0x5f432d,
	0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x76553a, 0x555555, 0x463020,
	0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x463020, 0x5f432d, 0x5f432d,
	0x463020, 0x76553a, 0x5f432d, 0x5f432d, 0x916848, 0x463020, 0x5f432d,
	0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x916848, 0x76553a,
	0x463020, 0x5f432d, 0x5f432d, 0x5f432d, 0x76553a, 0x916848, 0x76553a,
	0x463020, 0x916848, 0x76553a, 0x5f432d, 0x76553a, 0x5f432d, 0x5f432d,
	0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x916848, 0x5f432d, 0x76553a,
	0x5f432d, 0x463020, 0x916848, 0x76553a, 0x463020, 0x5f432d, 0x5f432d,
	0x76553a, 0x463020, 0x5f432d, 0x6a6a6a, 0x5f432d, 0x916848, 0x76553a,
	0x76553a, 0x5f432d, 0x916848, 0x463020, 0x5f432d, 0x5f432d, 0x5f432d,
	0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x76553a, 0x5f432d, 0x463020,
	0x916848, 0x76553a, 0x76553a, 0x463020
};

unsigned int texGrassSide[] = {
	0x5b8d3a, 0x5c8e3b, 0x6f9349, 0x463020, 0x76553a, 0x5f432d, 0x916848,
	0x5f432d, 0x76553a, 0x5f432d, 0x5f432d, 0x76553a, 0x5f432d, 0x5f432d,
	0x76553a, 0x76553a, 0x5d8f3c, 0x558734, 0x463020, 0x555555, 0x5f432d,
	0x463020, 0x5f432d, 0x5f432d, 0x5f432d, 0x76553a, 0x76553a, 0x5f432d,
	0x463020, 0x76553a, 0x5f432d, 0x5f432d, 0x5a8c39, 0x6c9147, 0x7a9f55,
	0x463020, 0x76553a, 0x76553a, 0x5f432d, 0x916848, 0x5f432d, 0x463020,
	0x5f432d, 0x5f432d, 0x76553a, 0x5f432d, 0x463020, 0x916848, 0x50822f,
	0x658a40, 0x4e812d, 0x463020, 0x916848, 0x76553a, 0x5f432d, 0x916848,
	0x76553a, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x916848,
	0x76553a, 0x50822f, 0x678c41, 0x528531, 0x598b38, 0x463020, 0x5f432d,
	0x6a6a6a, 0x76553a, 0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x76553a,
	0x5b4535, 0x5f432d, 0x76553a, 0x578936, 0x463020, 0x463020, 0x463020,
	0x76553a, 0x76553a, 0x5f432d, 0x76553a, 0x76553a, 0x463020, 0x5f432d,
	0x916848, 0x76553a, 0x5f432d, 0x463020, 0x5f432d, 0x4a7d2a, 0x528431,
	0x588a37, 0x463020, 0x5f432d, 0x463020, 0x5f432d, 0x5f432d, 0x5f432d,
	0x463020, 0x916848, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x6a6a6a,
	0x558734, 0x4d7f2c, 0x463020, 0x463020, 0x5f432d, 0x463020, 0x916848,
	0x5f432d, 0x463020, 0x5f432d, 0x76553a, 0x76553a, 0x5f432d, 0x76553a,
	0x463020, 0x5f432d, 0x639542, 0x4a7d2a, 0x5b8d3a, 0x4a7d2a, 0x463020,
	0x463020, 0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x463020, 0x555555,
	0x5f432d, 0x5f432d, 0x916848, 0x76553a, 0x5d8f3c, 0x73984e, 0x649643,
	0x463020, 0x463020, 0x5f432d, 0x5f432d, 0x463020, 0x76553a, 0x5f432d,
	0x916848, 0x76553a, 0x5f432d, 0x463020, 0x916848, 0x76553a, 0x538532,
	0x71964b, 0x72974d, 0x558835, 0x463020, 0x5f432d, 0x916848, 0x76553a,
	0x76553a, 0x5f432d, 0x916848, 0x76553a, 0x5f432d, 0x916848, 0x5f432d,
	0x5f432d, 0x518330, 0x5a8c39, 0x769b51, 0x463020, 0x555555, 0x463020,
	0x916848, 0x76553a, 0x5f432d, 0x5f432d, 0x463020, 0x5f432d, 0x5f432d,
	0x463020, 0x76553a, 0x5f432d, 0x528531, 0x4c7e2b, 0x463020, 0x5f432d,
	0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x5f432d, 0x916848, 0x76553a,
	0x463020, 0x5f432d, 0x5f432d, 0x5f432d, 0x76553a, 0x4c7e2b, 0x558734,
	0x447623, 0x463020, 0x76553a, 0x5f432d, 0x76553a, 0x5f432d, 0x5f432d,
	0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x916848, 0x5f432d, 0x76553a,
	0x3f711e, 0x518330, 0x4b7d2a, 0x463020, 0x463020, 0x5f432d, 0x5f432d,
	0x76553a, 0x463020, 0x5f432d, 0x6a6a6a, 0x5f432d, 0x916848, 0x76553a,
	0x76553a, 0x5f432d, 0x558835, 0x548633, 0x463020, 0x5f432d, 0x5f432d,
	0x916848, 0x76553a, 0x76553a, 0x5f432d, 0x76553a, 0x5f432d, 0x463020,
	0x916848, 0x76553a, 0x76553a, 0x463020
};

// Configuration
#define worldSX 16
#define worldSY 16
#define worldSZ 16

#define skyColor RGB(158, 207, 255)

#define hFov 90

// Macros
#define IN_WORLD(x, y, z) \
	(x >= 0 && y >= 0 && z >= 0 && x < worldSX && y < worldSY && z < worldSZ)

#define RGB(r, g, b) ((0xff << 24) | ((r) << 16) | ((g) << 8) | (b))

#define RED(col) (((col) & 0xff0000) >> 16)
#define GREEN(col) (((col) & 0x00ff00) >> 8)
#define BLUE(col) ((col) & 0x0000ff)

#define INV_COLOR(col) RGB(255 - RED(col), 255 - GREEN(col), 255 - BLUE(col))

#define UNLIT_COL(col) (UNLIT_RED(col) | UNLIT_GREEN(col) | UNLIT_BLUE(col))
#define UNLIT_RED(col) ((RED(col) * 2 / 3) << 16)
#define UNLIT_GREEN(col) ((GREEN(col) * 2 / 3) << 8)
#define UNLIT_BLUE(col) (BLUE(col) * 2 / 3)

#define CURTIME() (clock() / (float) CLOCKS_PER_SEC)

// Types
typedef struct vec3_t {
	float x, y, z;
} vec3;

typedef struct hit_t {
	bool hit;
	int x, y, z;
	int nx, ny, nz;
	float dist;
} hit;

enum block_t {
	BLOCK_AIR,
	BLOCK_DIRT
};

enum face_t {
	FACE_LEFT,
	FACE_RIGHT,
	FACE_BOTTOM,
	FACE_TOP,
	FACE_BACK,
	FACE_FRONT
};

// Functions
void initVideo();
void mainLoop();

void initWorld();
int getLight(int x, int z);
unsigned char getBlock(int x, int y, int z);
void setBlock(int x, int y, int z, unsigned char type);

void handleInput(unsigned int key, bool down);
void update(float dt);
void handleCollision(vec3 pos, vec3* velocity);
void drawFrame();

void setPos(float x, float y, float z);
void setView(float yaw, float pitch);
unsigned int raytrace(vec3 pos, vec3 dir, hit* info);
unsigned int rayColor(int x, int y, int z, int tex, int face);
void faceNormal(int face, int* x, int* y, int* z);
int texIndex(vec3 pos, int face);
vec3 rayDir(int x, int y);

unsigned char world[worldSX * worldSY * worldSZ] = {0};
unsigned char lighting[worldSX * worldSY] = {0};

vec3 playerPos = {8, 10, 9};

// The sine and cosine are the same for all pixels
float pitch = 0.0f;
float pitchC = 1.0f;
float pitchS = 0.0f;

float yaw = 0.0f;
float yawC = 1.0f;
float yawS = 0.0f;

// Input
float lastUpdate = 0.0f;

float dPitch = 0.0f;
float dYaw = 0.0f;

bool keyA = false;
bool keyW = false;
bool keyS = false;
bool keyD = false;

vec3 velocity = {0, 0, 0};

uint8_t* bvram;
int cancrftRunning = 0;
int rendering = 0;

static void cos_task()
{
	if (cancrftRunning) {
		return;
	}
	
	msleep(1000);
	console_clear();
	console_show();
	printf("%s\n", "Port of MineAssemble C, by @overv on Github");
	printf("%s", "Ported to Magic Lantern by @petabyt");

	bvram = bmp_vram();
	initWorld();

	cancrftRunning = 1;
}

static struct menu_entry cos_menu[] =
{
	{
		.name	   = "CanonCraft",
		.select	 = run_in_separate_task,
		.priv	   = cos_task,
		.help	   = "Minecraft on DSLR",
	},
};


static unsigned int cancrft_keypress(unsigned int key) {
	if (!cancrftRunning) {
		return 1;
	}

	if (rendering) {
		return 0;
	}

	rendering = 1;
	handleInput(key, 1);
	msleep(10);
	update(0.3f);
	handleInput(key, 0);
	drawFrame();
	rendering = 0;
	msleep(100);
	return 0;
}

static unsigned int cos_init()
{
	menu_add("Debug", cos_menu, COUNT(cos_menu));
	return 0;
}

static unsigned int cos_deinit()
{
	return 0;
}

// MIT License - MineAssemble Reference
// https://github.com/Overv/MineAssemble/tree/master/reference

void initWorld() {
	// Make flat grass landscape
	for (int x = 0; x < worldSX; x++) {
		for (int y = 0; y < worldSY; y++) {
			for (int z = 0; z < worldSZ; z++) {
				setBlock(x, y, z, y >= worldSY / 2 ? BLOCK_AIR : BLOCK_DIRT);
			}
		}
	}

	// Add arch
	setBlock(11, 8, 4, BLOCK_DIRT);
	setBlock(11, 9, 4, BLOCK_DIRT);
	setBlock(11, 10, 4, BLOCK_DIRT);
	setBlock(10, 10, 4, BLOCK_DIRT);
	setBlock(9, 10, 4, BLOCK_DIRT);
	setBlock(9, 9, 4, BLOCK_DIRT);
	setBlock(9, 8, 4, BLOCK_DIRT);
	setBlock(9, 12, 4, BLOCK_DIRT);

	// Initial player position
	setPos(8.0f, 9.8f, 8.0f);
	setView(0.0f, -0.35f);
}

int getLight(int x, int z) {
	return lighting[x * worldSZ + z];
}

unsigned char getBlock(int x, int y, int z) {
	return world[x * worldSY * worldSZ + y * worldSZ + z];
}

void setBlock(int x, int y, int z, unsigned char type) {
	world[x * worldSY * worldSZ + y * worldSZ + z] = type;

	// Update lightmap
	int lightIdx = x * worldSZ + z;
	
	if (type != BLOCK_AIR && lighting[lightIdx] < y) {
		lighting[lightIdx] = y;
	} else if (type == BLOCK_AIR && lighting[lightIdx] <= y) {
		y = worldSY - 1;

		while (y > 0 && getBlock(x, y, z) == BLOCK_AIR) {
			y--;
		}

		lighting[lightIdx] = y;
	}
}

void handleInput(unsigned int key, bool down) {
	hit info;
	
	velocity.x = velocity.z = 0.0f;
	
	switch (key) {
#if 0
		// View
		case 't': dPitch += down ? 1.0f : -1.0f; break;
		case 'g': dPitch += down ? -1.0f : 1.0f; break;

		case 'f': dYaw += down ? 1.0f : -1.0f; break;
		case 'h': dYaw += down ? -1.0f : 1.0f; break;
#endif
		// Movement
		case MODULE_KEY_PRESS_LEFT: {
				velocity.x += 2.0f * cosf(M_PI - yaw);
				velocity.z += 2.0f * sinf(M_PI - yaw);
			}
			break;
		case MODULE_KEY_PRESS_UP: {
				velocity.x += 2.0f * cosf(-M_PI / 2 - yaw);
				velocity.z += 2.0f * sinf(-M_PI / 2 - yaw);
			}
			break;
		case MODULE_KEY_PRESS_DOWN: {
				velocity.x += 2.0f * cosf(M_PI / 2 - yaw);
				velocity.z += 2.0f * sinf(M_PI / 2 - yaw);
			}
			break;
		case MODULE_KEY_PRESS_RIGHT: {
				velocity.x += 2.0f * cosf(-yaw);
				velocity.z += 2.0f * sinf(-yaw);
			}
			break;
		
		// Check if a block was hit and place a new block next to it
		case MODULE_KEY_PRESS_SET:
			if (!down) {
				raytrace(playerPos, rayDir(160, 100), &info);

				if (info.hit) {
					int bx = info.x + info.nx;
					int by = info.y + info.ny;
					int bz = info.z + info.nz;

					if (IN_WORLD(bx, by, bz)) {
						setBlock(bx, by, bz, BLOCK_DIRT);
					}
				}
			}
			break;

		// Check if a block was hit and remove it
		case MODULE_KEY_Q:
			if (!down) {
				raytrace(playerPos, rayDir(160, 100), &info);

				if (info.hit) {
					setBlock(info.x, info.y, info.z, BLOCK_AIR);
				}
			}
			break;
		default:
			break;
	}

	playerPos.x += velocity.x * 0.3f;
	playerPos.y += velocity.y * 0.3f;
	playerPos.z += velocity.z * 0.3f; 
}

void update(float dt) {
	// Update view
	pitch += 1.2f * dPitch * dt;
	yaw += 1.2f * dYaw * dt;

	setView(pitch, yaw);

	// Simulate gravity
	velocity.y -= 20.0f * dt;

	// Handle block collision (head, lower body and feet)
	vec3 headPos = playerPos;
	vec3 lowerPos = playerPos; lowerPos.y -= 1.0f;
	vec3 footPos = playerPos; footPos.y -= 1.8f;

	handleCollision(headPos, &velocity);
	handleCollision(lowerPos, &velocity);
	handleCollision(footPos, &velocity);
	
}

void handleCollision(vec3 pos, vec3* velocity) {
	// Check if new position is not inside block
	hit info;
	raytrace(pos, *velocity, &info);
	
	// If it is, create sliding motion by negating velocity based on hit normal
	if (info.hit && info.dist < 0.1f) {
		if (info.nx != 0) velocity->x = 0.0f;
		if (info.ny != 0) velocity->y = 0.0f;
		if (info.nz != 0) velocity->z = 0.0f;
	}
}

void drawFrame() {
	int x = 0;
	int y = 0;

	// Draw world
	for (int i = 0; i < 320 * 200; i++) {
		// TODO: Convert 32 bit color to ML color
		int col = raytrace(playerPos, rayDir(x, y), NULL);
		bmp_putpixel(x, y, (char)col);

		x++;
		if (x == 320) {
			x = 0;
			y++;
		}
	}
}

void setPos(float x, float y, float z) {
	playerPos.x = x;
	playerPos.y = y;
	playerPos.z = z;
}

void setView(float p, float y) {
	pitch = p;

	if (pitch > 1.57f) pitch = 1.57f;
	else if (pitch < -1.57f) pitch = -1.57f;

	pitchS = sinf(pitch);
	pitchC = cosf(pitch);

	yaw = y;
	yawS = sinf(yaw);
	yawC = cosf(yaw);
}

// Returns final color
unsigned int raytrace(vec3 pos, vec3 dir, hit* info) {
	// Finish early if there's no direction
	if (dir.x == 0.0f && dir.y == 0.0f && dir.z == 0.0f) {
		goto nohit;
	}

	vec3 start = pos;

	int x = (int) pos.x;
	int y = (int) pos.y;
	int z = (int) pos.z;

	int x_dir = dir.x >= 0.0f ? 1 : -1;
	int y_dir = dir.y >= 0.0f ? 1 : -1;
	int z_dir = dir.z >= 0.0f ? 1 : -1;

	float dx_off = x_dir > 0 ? 1.0f : 0.0f;
	float dy_off = y_dir > 0 ? 1.0f : 0.0f;
	float dz_off = z_dir > 0 ? 1.0f : 0.0f;

	int x_face = x_dir > 0 ? FACE_LEFT : FACE_RIGHT;
	int y_face = y_dir > 0 ? FACE_BOTTOM : FACE_TOP;
	int z_face = z_dir > 0 ? FACE_BACK : FACE_FRONT;

	int face = FACE_TOP;
	
	// Assumption is made that the camera is never outside the world
	while (IN_WORLD(x, y, z)) {
		// Determine if block is solid
		if (getBlock(x, y, z) != BLOCK_AIR) {
			float dx = start.x - pos.x;
			float dy = start.y - pos.y;
			float dz = start.z - pos.z;
			float dist = sqrtf(dx*dx + dy*dy + dz*dz);

			pos.x -= x;
			pos.y -= y;
			pos.z -= z;

			// If hit info is requested, no color computation is done
			if (info != NULL) {
				int nx, ny, nz;
				faceNormal(face, &nx, &ny, &nz);

				info->hit = true;
				info->x = x;
				info->y = y;
				info->z = z;
				info->nx = nx;
				info->ny = ny;
				info->nz = nz;
				info->dist = dist;
			}

			int tex = texIndex(pos, face);

			return rayColor(x, y, z, tex, face);
		}

		// Remaining distance inside this block given ray direction
		float dx = x - pos.x + dx_off;
		float dy = y - pos.y + dy_off;
		float dz = z - pos.z + dz_off;
		
		// Calculate distance for each dimension
		float t1 = dx / dir.x;
		float t2 = dy / dir.y;
		float t3 = dz / dir.z;
		
		// Find closest hit
		if (t1 <= t2 && t1 <= t3) {
			pos.x += dx;
			pos.y += t1 * dir.y;
			pos.z += t1 * dir.z;
			x += x_dir;
			face = x_face;
		}
		if (t2 <= t1 && t2 <= t3) {
			pos.x += t2 * dir.x;
			pos.y += dy;
			pos.z += t2 * dir.z;
			y += y_dir;
			face = y_face;
		}
		if (t3 <= t1 && t3 <= t2) {
			pos.x += t3 * dir.x;
			pos.y += t3 * dir.y;
			pos.z += dz;
			z += z_dir;
			face = z_face;
		}
	}

nohit:
	if (info != NULL) {
		info->hit = false;
	}

	return skyColor;
}

unsigned int rayColor(int x, int y, int z, int tex, int face) {
	// Get normal
	int nx, ny, nz;
	faceNormal(face, &nx, &ny, &nz);

	// Block is dirt if there's another block directly on top of it
	bool isDirt = y < worldSY - 1 && getBlock(x, y + 1, z) != BLOCK_AIR;

	// Texture lookup
	unsigned int texColor;

	if (face == FACE_BOTTOM || isDirt) {
		texColor = texDirt[tex];
	} else if (face == FACE_TOP) {
		texColor = texGrass[tex];
	} else {
		texColor = texGrassSide[tex];
	}

	// Side is dark if there are higher blocks in the column faced by it
	// Left and back sides are always dark to simulate a sun angle
	if (IN_WORLD(x + nx, y, z + nz) && getLight(x + nx, z + nz) > y) {
		return UNLIT_COL(texColor);
	} else if (face == FACE_BOTTOM || face == FACE_LEFT || face == FACE_BACK) {
		return UNLIT_COL(texColor);
	} else {
		return texColor;
	}
}

void faceNormal(int face, int* x, int* y, int* z) {
	*x = 0;
	*y = 0;
	*z = 0;

	switch (face) {
		case FACE_LEFT: *x = -1; break;
		case FACE_RIGHT: *x = 1; break;
		case FACE_BOTTOM: *y = -1; break;
		case FACE_TOP: *y = 1; break;
		case FACE_BACK: *z = -1; break;
		case FACE_FRONT: *z = 1; break;
	}
}

int texIndex(vec3 pos, int face) {
	float u = 0, v = 0;

	switch (face) {
		case FACE_LEFT: u = pos.z; v = pos.y; break;
		case FACE_RIGHT: u = pos.z; v = pos.y; break;
		case FACE_BOTTOM: u = pos.x; v = pos.z; break;
		case FACE_TOP: u = pos.x; v = pos.z; break;
		case FACE_BACK: u = pos.x; v = pos.y; break;
		case FACE_FRONT: u = pos.x; v = pos.y; break;
	}

	v = 1.0f - v;

	return ((int) (u * 15.0f)) * 16 + (int) (v * 15.0f);
}

vec3 rayDir(int x, int y) {
	static float vFov = -1, fov;

	// Calculate vertical fov and fov constant from specified horizontal fov
	if (vFov == -1) {
		vFov = 2.0f * atanf(tanf(hFov / 720.0f * M_PI) * 320.0f / 200.0f);
		fov = tanf(0.5f * vFov);
	}

	// This is simply a precomputed version of the actual linear
	// transformation, which is the inverse of the common view and
	// projection transformation used in rasterization.
	float clipX = x / 160.0f - 1.0f;
	float clipY = 1.0f - y / 100.0f;

	vec3 d = {
		1.6f * fov * yawC * clipX + fov * yawS * pitchS * clipY - pitchC * yawS,
		fov * pitchC * clipY + pitchS,
		-1.6f * fov * yawS * clipX + fov * yawC * pitchS * clipY - pitchC * yawC
	};

	// Normalize
	float length = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
	d.x /= length;
	d.y /= length;
	d.z /= length;

	return d;
}


MODULE_INFO_START()
	MODULE_INIT(cos_init)
	MODULE_DEINIT(cos_deinit)
MODULE_INFO_END()

MODULE_CBRS_START()
	MODULE_CBR(CBR_KEYPRESS, cancrft_keypress, 0)
MODULE_CBRS_END()
