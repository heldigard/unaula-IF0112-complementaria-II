# Script PowerShell para agregar navegación a todos los archivos HTML de clases
# Debe ejecutarse desde el directorio clases-html

$basePath = "F:\UNAULA\IF0112-complementaria-II\clases-html"

# Orden de las clases
$ordenClases = @(
    @{ archivo = "presentacion-docente.html"; anterior = $null; siguiente = "clase-00.html" },
    @{ archivo = "clase-00.html"; anterior = "presentacion-docente.html"; siguiente = "clase-01.html" },
    @{ archivo = "clase-01.html"; anterior = "clase-00.html"; siguiente = "clase-02.html" },
    @{ archivo = "clase-02.html"; anterior = "clase-01.html"; siguiente = "clase-02-materiales.html" },
    @{ archivo = "clase-02-materiales.html"; anterior = "clase-02.html"; siguiente = "clase-03.html" },
    @{ archivo = "clase-03.html"; anterior = "clase-02-materiales.html"; siguiente = "clase-04.html" },
    @{ archivo = "clase-04.html"; anterior = "clase-03.html"; siguiente = "clase-05.html" },
    @{ archivo = "clase-05.html"; anterior = "clase-04.html"; siguiente = "clase-06.html" },
    @{ archivo = "clase-06.html"; anterior = "clase-05.html"; siguiente = "clase-07.html" },
    @{ archivo = "clase-07.html"; anterior = "clase-06.html"; siguiente = "clase-08.html" },
    @{ archivo = "clase-08.html"; anterior = "clase-07.html"; siguiente = "examen-E3.html" },
    @{ archivo = "examen-E3.html"; anterior = "clase-08.html"; siguiente = "clase-09.html" },
    @{ archivo = "clase-09.html"; anterior = "examen-E3.html"; siguiente = "clase-10.html" },
    @{ archivo = "clase-10.html"; anterior = "clase-09.html"; siguiente = "clase-11.html" },
    @{ archivo = "clase-11.html"; anterior = "clase-10.html"; siguiente = "clase-12.html" },
    @{ archivo = "clase-12.html"; anterior = "clase-11.html"; siguiente = "clase-13.html" },
    @{ archivo = "clase-13.html"; anterior = "clase-12.html"; siguiente = "clase-14.html" },
    @{ archivo = "clase-14.html"; anterior = "clase-13.html"; siguiente = "clase-15.html" },
    @{ archivo = "clase-15.html"; anterior = "clase-14.html"; siguiente = $null },
    @{ archivo = "_glossary.html"; anterior = "clase-15.html"; siguiente = $null }
)

# Estilos CSS para la navegación
$cssNav = @'
        /* ============================================
           NAVIGATION BETWEEN CLASSES
           ============================================ */
        .class-nav {
            background: linear-gradient(135deg, #1e40af 0%, #3b82f6 100%);
            padding: var(--space-6);
            margin-top: var(--space-12);
            border-radius: var(--radius-lg);
        }

        .class-nav-title {
            color: white;
            font-size: var(--text-sm);
            text-align: center;
            margin-bottom: var(--space-4);
            opacity: 0.9;
        }

        .class-nav-links {
            display: flex;
            justify-content: center;
            gap: var(--space-4);
            flex-wrap: wrap;
        }

        .class-nav-btn {
            display: inline-flex;
            align-items: center;
            gap: var(--space-2);
            padding: var(--space-3) var(--space-5);
            background: rgba(255, 255, 255, 0.15);
            color: white;
            text-decoration: none;
            border-radius: var(--radius-md);
            font-size: var(--text-sm);
            font-weight: 500;
            transition: all 0.2s ease;
            border: 1px solid rgba(255, 255, 255, 0.2);
        }

        .class-nav-btn:hover {
            background: rgba(255, 255, 255, 0.25);
            transform: translateY(-2px);
        }

        .class-nav-btn.disabled {
            opacity: 0.4;
            pointer-events: none;
        }

        .class-nav-btn .arrow {
            font-size: var(--text-lg);
        }
'@

# HTML de navegación
function Get-NavHTML {
    param([string]$Anterior, [string]$Siguiente)

    $html = @"
        <!-- Navegación entre clases -->
        <nav class="class-nav">
            <div class="class-nav-title">Navegación del Curso</div>
            <div class="class-nav-links">
                <a href="index.html" class="class-nav-btn">
                    <span class="arrow">🏠</span> Inicio
                </a>
"@

    if ($Anterior) {
        $html += @"
                <a href="$Anterior" class="class-nav-btn">
                    <span class="arrow">←</span> Clase Anterior
                </a>
"@
    }

    if ($Siguiente) {
        $html += @"
                <a href="$Siguiente" class="class-nav-btn">
                    Clase Siguiente <span class="arrow">→</span>
                </a>
"@
    }

    $html += @"
            </div>
        </nav>
"@

    return $html
}

# Procesar cada archivo
foreach ($clase in $ordenClases) {
    $archivo = $clase.archivo
    $rutaCompleta = Join-Path $basePath $archivo

    if (-not (Test-Path $rutaCompleta)) {
        Write-Host "⚠️ No encontrado: $archivo" -ForegroundColor Yellow
        continue
    }

    Write-Host "Procesando: $archivo..." -ForegroundColor Cyan

    $contenido = Get-Content $rutaCompleta -Raw

    # Verificar si ya tiene navegación
    if ($contenido -match 'class-nav') {
        Write-Host "  ✅ Ya tiene navegación" -ForegroundColor Green
        continue
    }

    # Agregar estilos CSS antes de BACK TO TOP BUTTON
    if ($contenido -match '\}\s*\n\s*\/\* =\s+BACK TO TOP') {
        $contenido = $contenido -replace '\}\s*\n\s*\/\* =\s+BACK TO TOP', "$cssNav`n`n        /* ============================================
           BACK TO TOP BUTTON"
        Write-Host "  ✅ CSS agregado" -ForegroundColor Green
    } else {
        Write-Host "  ⚠️ No se encontró posición para CSS" -ForegroundColor Yellow
    }

    # Agregar HTML de navegación antes del footer
    $navHTML = Get-NavHTML -Anterior $clase.anterior -Siguiente $clase.siguiente
    if ($contenido -match '</main>\s*\n\s*<footer>') {
        $contenido = $contenido -replace '</main>\s*\n\s*<footer>', "</main>`n`n$navHTML`n`n    <footer>"
        Write-Host "  ✅ Navegación HTML agregada" -ForegroundColor Green
    } else {
        Write-Host "  ⚠️ No se encontró posición para HTML" -ForegroundColor Yellow
    }

    # Guardar archivo
    $contenido | Set-Content $rutaCompleta -Encoding UTF8
}

Write-Host "`n✅ Proceso completado" -ForegroundColor Green
