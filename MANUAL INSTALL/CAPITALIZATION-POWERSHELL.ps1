Add-Type -AssemblyName System.Windows.Forms

function Copy-Uppercased-Files {
    param([string]$sourcePath)

    $log = @()

    $parentPath = Split-Path $sourcePath -Parent
    $sourceName = Split-Path $sourcePath -Leaf
    $targetRoot = Join-Path $parentPath ($sourceName.ToUpper() + "-CAPS")

    # Create root target folder
    if (!(Test-Path $targetRoot)) {
        New-Item -ItemType Directory -Path $targetRoot | Out-Null
    }

    $items = Get-ChildItem -Recurse -Force -Path $sourcePath

    foreach ($item in $items) {
        $relPath = $item.FullName.Substring($sourcePath.Length).TrimStart('\','/')
        $relParts = $relPath -split '[\\/]'
        $upperParts = $relParts | ForEach-Object { $_.ToUpper() }

        $targetPath = Join-Path $targetRoot ($upperParts -join "\")

        if ($item.PSIsContainer) {
            if (!(Test-Path $targetPath)) {
                try {
                    New-Item -ItemType Directory -Path $targetPath -Force | Out-Null
                    $log += "📁 CREATED: $targetPath"
                } catch {
                    $log += "✖ FAILED DIR: $targetPath"
                }
            }
        } else {
            $targetFolder = Split-Path $targetPath -Parent
            if (!(Test-Path $targetFolder)) {
                New-Item -ItemType Directory -Path $targetFolder -Force | Out-Null
            }

            try {
                Copy-Item -LiteralPath $item.FullName -Destination $targetPath -Force
                $log += "✔ COPIED: $relPath → $($targetPath.Substring($targetRoot.Length + 1))"
            } catch {
                $log += "✖ FAILED FILE: $relPath"
            }
        }
    }

    return $log
}

function Show-Log($lines) {
    $form = New-Object Windows.Forms.Form
    $form.Text = "Uppercase Copy Log"
    $form.Size = New-Object Drawing.Size(700, 400)
    $form.StartPosition = "CenterScreen"

    $listBox = New-Object Windows.Forms.ListBox
    $listBox.Size = New-Object Drawing.Size(660, 320)
    $listBox.Location = New-Object Drawing.Point(10, 10)
    $listBox.HorizontalScrollbar = $true
    $form.Controls.Add($listBox)

    $btn = New-Object Windows.Forms.Button
    $btn.Text = "Close"
    $btn.Location = New-Object Drawing.Point(600, 340)
    $btn.Size = New-Object Drawing.Size(75, 25)
    $btn.Add_Click({ $form.Close() })
    $form.Controls.Add($btn)

    $lines | ForEach-Object { $listBox.Items.Add($_) }

    $form.ShowDialog()
}

# GUI folder picker
$picker = New-Object Windows.Forms.FolderBrowserDialog
$picker.Description = "Select folder to copy into ALL UPPERCASE"
$picker.ShowNewFolderButton = $false

if ($picker.ShowDialog() -eq [System.Windows.Forms.DialogResult]::OK) {
    $log = Copy-Uppercased-Files -sourcePath $picker.SelectedPath
    Show-Log $log
}
