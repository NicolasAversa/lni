# TP Final: Objeto interactivo

En grupos de 4 a 6 integrantes:

## 📝 Ideación:

Pensar una huella (sentimiento) que pueda ser expresada mediante el comportamiento y la comunicación no verbal en un objeto interactivo.

### Campo asociativo

Construir un mapa conceptual a partir de la huella seleccionada, desarrollando un campo asociativo compuesto por un mínimo de diez palabras entre sustantivos, adjetivos y verbos. Este mapa deberá explorar las acciones, cualidades, relaciones y situaciones que contribuyen a la construcción de sentido del concepto elegido.

### Mapa de marcas y huellas

A partir del análisis realizado en el campo asociativo, diseñar un sistema de como mínimo 5 marcas de comportamiento (del objeto y del usuario) que comunique la huella seleccionada. ¿Cómo producen sentido?

## 🪛 Implementación

Implementar la propuesta diseñada mediante el entorno Arduino, utilizando:

- Sensores: para capturar la conducta corporal del usuario
- Actuadores: para manifestar la respuesta expresiva del sistema

## 🗓️ Fechas de Entrega:

### 📦 Formato de Entrega:

- Muestra funcional: Emplazar el objeto interactivo en el espacio asignado, sobre un atril negro (seleccionar materiales de construcción según las necesidades de la obra). Los elementos que no formen parte de la construcción de sentido de la obra deben estar ocultos dentro del atril.
- Entrega impresa del mapa de marcas y huellas:
- Entrega digital en PDF que incluya:
    - Desarrollo de la Ideación
    - Registro audiovisual: link a video (máximo 2 min) donde se observe claramente la interacción del usuario poniendo el cuerpo y la respuesta del dispositivo.
    - Nómina de integrantes (foto y nombre).

[Visualizador](https://ochafik.com/openscad2/)

<details>

<summary>Atril</summary>

```openscad
/*
 ==============================================================================
  PARAMETRIC INTERACTIVE ART PEDESTAL / PLINTH STRUCTURE
 ==============================================================================
  Description:
    Parametric OpenSCAD model of a 30 x 30 x 100 cm display pedestal box.
    Designed for interactive art installations (up to 30 x 30 x 30 cm max).
    Features an internal wooden support skeleton (corner posts, rails, top plate,
    cable management hole) covered by a solid black wrap (fabric/paper/acrylic).
 
  Key Features:
    - Adjustable height (default 100 cm, easily modified via slider or variable).
    - OpenSCAD Customizer compatible (GUI sliders & dropdowns).
    - Multiple view modes: Assembled, X-Ray / Transparent, Wooden Skeleton,
      Black Covering Only, and Exploded Construction View.
    - Interactive art mockup display (30x30x30 cm max boundary).
    - Unit scale option: default in cm; set unit_scale = 10 for mm (3D printing).
 ==============================================================================
*/

/* [Overall Pedestal Dimensions] */
// Width of the pedestal base (X axis, default 30 cm)
width = 30; // [15:1:60]

// Depth of the pedestal base (Y axis, default 30 cm)
depth = 30; // [15:1:60]

// Height of the pedestal structure (Z axis, default 100 cm - MODIFY AS NEEDED)
height = 100; // [40:5:200]

// Unit scaling: 1 = centimeters (cm), 10 = millimeters (mm)
unit_scale = 1; // [1:Centimeters (cm), 10:Millimeters (mm)]

/* [Wood Framing & Carpentry] */
// Width/thickness of timber framing studs (e.g. 2.5x2.5 cm timber battens / 1x1 lumber)
timber_size = 2.5; // [1.5:0.5:5.0]

// Thickness of top wooden platform (e.g. 1.8 cm / 18 mm plywood or MDF)
top_plate_thickness = 1.8; // [1.0:0.2:3.0]

// Thickness of bottom base plate (1.8 cm, or 0 for open hollow bottom)
bottom_plate_thickness = 1.8; // [0:0.2:3.0]

// Include mid-height horizontal reinforcement braces (recommended for height >= 80 cm)
add_mid_bracing = true;

// Cable pass-through hole for interactive electronics / power cords (diameter in cm, 0 = none)
cable_hole_diameter = 4.0; // [0:0.5:8.0]

/* [Covering (Fabric / Paper / Skin)] */
// Thickness of outer black covering material (cloth, poster board, or thin veneer)
covering_thickness = 0.2; // [0.1:0.05:1.0]

// Color of the outer covering (default: solid deep matte black)
covering_color = [0.08, 0.08, 0.08];

/* [Interactive Art Mockup] */
// Show the 30x30x30 cm interactive art object on top
show_art = true;

// Art piece width (X axis, max 30 cm)
art_width = 30; // [5:1:30]

// Art piece depth (Y axis, max 30 cm)
art_depth = 30; // [5:1:30]

// Art piece height (Z axis, max 30 cm)
art_height = 30; // [5:1:30]

/* [Visualization & View Mode] */
// Choose how the structure is rendered in OpenSCAD
view_mode = "assembled"; // [assembled:Full Assembly (Wood + Black Covering + Art), xray:X-Ray / Semi-Transparent Covering, wood_only:Bare Wooden Frame & Skeleton Only, covering_only:Solid Black Outer Box Only, exploded:Exploded Assembly View]

// Explode distance between components (used when view_mode is 'exploded')
explode_offset = 12; // [5:1:30]

// Level of polygon detail for cylinders/holes
$fn = 48;

// ----------------------------------------------------------------------------
// SCALED VARIABLES (Multiplied by unit_scale)
// ----------------------------------------------------------------------------
W   = width * unit_scale;
D   = depth * unit_scale;
H   = height * unit_scale;
T   = timber_size * unit_scale;
TP  = top_plate_thickness * unit_scale;
BP  = bottom_plate_thickness * unit_scale;
CHD = cable_hole_diameter * unit_scale;
CT  = covering_thickness * unit_scale;
EX  = explode_offset * unit_scale;

AW  = art_width * unit_scale;
AD  = art_depth * unit_scale;
AH  = art_height * unit_scale;

// Internal frame height between base and top deck
frame_H = H - TP - BP;

// ----------------------------------------------------------------------------
// COLOR DEFINITIONS
// ----------------------------------------------------------------------------
wood_color       = [0.82, 0.68, 0.48]; // Natural pine/birch timber frame
plywood_color    = [0.74, 0.58, 0.40]; // Top and bottom plywood plates
cloth_solid      = [0.07, 0.07, 0.07, 1.0]; // Solid black wrap
cloth_trans      = [0.15, 0.15, 0.15, 0.35]; // X-ray semi-transparent black
art_color        = [0.10, 0.65, 0.85, 0.60]; // Translucent cyan interactive art
sensor_color     = [1.00, 0.80, 0.20, 0.90]; // Interactive sensor/glow feature
cable_grommet    = [0.25, 0.25, 0.25]; // Dark plastic grommet ring

// ============================================================================
// MAIN ASSEMBLY LOGIC
// ============================================================================

scale([1, 1, 1]) {
    if (view_mode == "assembled") {
        render_wooden_structure();
        render_covering(cloth_solid, 0);
        if (show_art) render_art_piece(0);
    }
    else if (view_mode == "xray") {
        render_wooden_structure();
        render_covering(cloth_trans, 0);
        if (show_art) render_art_piece(0);
    }
    else if (view_mode == "wood_only") {
        render_wooden_structure();
        if (show_art) render_art_piece(0);
    }
    else if (view_mode == "covering_only") {
        render_covering(cloth_solid, 0);
        if (show_art) render_art_piece(0);
    }
    else if (view_mode == "exploded") {
        // Exploded view expands panels outward and raises top & art
        render_wooden_structure();
        render_covering(cloth_solid, EX);
        if (show_art) render_art_piece(EX * 2);
    }
}

// ============================================================================
// COMPONENT MODULES
// ============================================================================

// --- 1. FULL WOODEN INTERNAL STRUCTURE ---
module render_wooden_structure() {
    // Bottom Base Plate
    if (BP > 0) {
        color(plywood_color)
        translate([-W/2, -D/2, 0])
        cube([W, D, BP]);
    }

    // 4 Corner Vertical Timber Studs
    color(wood_color) {
        // Front-Left
        translate([-W/2, -D/2, BP])
        cube([T, T, frame_H]);

        // Front-Right
        translate([W/2 - T, -D/2, BP])
        cube([T, T, frame_H]);

        // Back-Left
        translate([-W/2, D/2 - T, BP])
        cube([T, T, frame_H]);

        // Back-Right
        translate([W/2 - T, D/2 - T, BP])
        cube([T, T, frame_H]);
    }

    // Horizontal Rails (Bottom & Top framing rings)
    color(wood_color) {
        // --- Bottom Perimeter Rails ---
        // Front rail
        translate([-W/2 + T, -D/2, BP])
        cube([W - 2*T, T, T]);
        // Back rail
        translate([-W/2 + T, D/2 - T, BP])
        cube([W - 2*T, T, T]);
        // Left rail
        translate([-W/2, -D/2 + T, BP])
        cube([T, D - 2*T, T]);
        // Right rail
        translate([W/2 - T, -D/2 + T, BP])
        cube([T, D - 2*T, T]);

        // --- Top Perimeter Rails ---
        // Front rail
        translate([-W/2 + T, -D/2, BP + frame_H - T])
        cube([W - 2*T, T, T]);
        // Back rail
        translate([-W/2 + T, D/2 - T, BP + frame_H - T])
        cube([W - 2*T, T, T]);
        // Left rail
        translate([-W/2, -D/2 + T, BP + frame_H - T])
        cube([T, D - 2*T, T]);
        // Right rail
        translate([W/2 - T, -D/2 + T, BP + frame_H - T])
        cube([T, D - 2*T, T]);

        // --- Optional Mid-Height Bracing ---
        if (add_mid_bracing && frame_H > 40 * unit_scale) {
            mid_z = BP + (frame_H - T) / 2;
            // Front mid rail
            translate([-W/2 + T, -D/2, mid_z])
            cube([W - 2*T, T, T]);
            // Back mid rail
            translate([-W/2 + T, D/2 - T, mid_z])
            cube([W - 2*T, T, T]);
            // Left mid rail
            translate([-W/2, -D/2 + T, mid_z])
            cube([T, D - 2*T, T]);
            // Right mid rail
            translate([W/2 - T, -D/2 + T, mid_z])
            cube([T, D - 2*T, T]);
        }
    }

    // Top Solid Mounting Platform (with optional cable pass-through hole)
    color(plywood_color)
    translate([0, 0, H - TP]) {
        difference() {
            // Solid wooden deck
            translate([-W/2, -D/2, 0])
            cube([W, D, TP]);

            // Cable pass-through hole for interactive art wiring
            if (CHD > 0) {
                translate([0, 0, -0.5])
                cylinder(h = TP + 1, d = CHD);
            }
        }
    }

    // Plastic Cable Grommet Ring (cosmetic detail)
    if (CHD > 0) {
        color(cable_grommet)
        translate([0, 0, H - TP - 0.2])
        difference() {
            cylinder(h = TP + 0.4, d = CHD + 0.8 * unit_scale);
            translate([0, 0, -0.5])
            cylinder(h = TP + 1.4, d = CHD);
        }
    }
}

// --- 2. BLACK COVERING (CLOTH / PAPER / LEATHERETTE WRAP) ---
module render_covering(cloth_clr, exp) {
    color(cloth_clr) {
        // Front Side Panel
        translate([-W/2 - CT, -D/2 - CT - exp, 0])
        cube([W + 2*CT, CT, H]);

        // Back Side Panel
        translate([-W/2 - CT, D/2 + exp, 0])
        cube([W + 2*CT, CT, H]);

        // Left Side Panel
        translate([-W/2 - CT - exp, -D/2, 0])
        cube([CT, D, H]);

        // Right Side Panel
        translate([W/2 + exp, -D/2, 0])
        cube([CT, D, H]);

        // Top Wrap / Border Flange (neatly framed edge)
        if (exp > 0) {
            // In exploded view, show top skin elevated
            translate([0, 0, H + exp])
            difference() {
                translate([-W/2 - CT, -D/2 - CT, 0])
                cube([W + 2*CT, D + 2*CT, CT]);

                if (CHD > 0) {
                    translate([0, 0, -0.5])
                    cylinder(h = CT + 1, d = CHD);
                }
            }
        }
    }
}

// --- 3. INTERACTIVE ART MOCKUP (MAX 30 x 30 x 30 cm) ---
module render_art_piece(art_exp) {
    art_z = H + art_exp;

    translate([0, 0, art_z]) {
        // Translucent Interactive Art Enclosure / Sculpture
        color(art_color)
        translate([-AW/2, -AD/2, 0])
        cube([AW, AD, AH]);

        // Internal Interactive Core / Glowing Element
        color(sensor_color) {
            // Interactive sensor / illuminated orb or tactile node
            translate([0, 0, AH * 0.45])
            sphere(d = min(AW, AD) * 0.4);

            // Sensor interface button / ring on top
            translate([0, 0, AH - 0.2 * unit_scale])
            cylinder(h = 0.5 * unit_scale, d = min(AW, AD) * 0.25);
        }

        // Bounding Frame Guide Lines (illustrating maximum 30x30x30 cm boundary)
        color([1.0, 1.0, 1.0, 0.4]) {
            // Subtle boundary markers at corners
            for (dx = [-AW/2, AW/2 - 0.5*unit_scale]) {
                for (dy = [-AD/2, AD/2 - 0.5*unit_scale]) {
                    translate([dx, dy, 0])
                    cube([0.5*unit_scale, 0.5*unit_scale, AH]);
                }
            }
        }
    }
}
```

</details>

