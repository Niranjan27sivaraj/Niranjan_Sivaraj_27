//HTML
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Water Level Monitoring System</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h1>Water Level Monitoring System</h1>
        <div class="water-tank">
            <div id="water" class="water"></div>
        </div>
        <p id="level-indicator">Water Level: 0%</p>
        <button onclick="simulateLevel()">Simulate Level Change</button>
    </div>
    <script src="script.js"></script>
</body>
</html>

//CSS
body {
    font-family: Arial, sans-serif;
    background-color: #f0f8ff;
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100vh;
    margin: 0;
}

.container {
    text-align: center;
}

.water-tank {
    width: 200px;
    height: 400px;
    border: 2px solid #000;
    position: relative;
    background: #ddd;
    margin: 20px auto;
    border-radius: 10px;
    overflow: hidden;
}

.water {
    position: absolute;
    bottom: 0;
    width: 100%;
    height: 0%;
    background: #1e90ff;
    transition: height 0.5s ease;
}

#level-indicator {
    margin: 20px;
    font-size: 18px;
}

//JAVA SCRIPT
let currentLevel = 0; // Water level percentage

// Function to simulate water level changes
function simulateLevel() {
    // Randomly set the water level for demonstration (0-100%)
    currentLevel = Math.floor(Math.random() * 101);
    updateWaterLevel(currentLevel);
}

// Function to update water level display and handle notifications
function updateWaterLevel(level) {
    const waterElement = document.getElementById('water');
    const levelIndicator = document.getElementById('level-indicator');

    // Update water level
    waterElement.style.height = `${level}%`;
    levelIndicator.textContent = `Water Level: ${level}%`;

    // Notifications based on water level
    if (level >= 100) {
        alert("Warning: Water tank is full and overflowing!");
    } else if (level >= 75) {
        alert("Notice: Water level is at 75%.");
    } else if (level <= 25) {
        alert("Warning: Water level is below 25%. Please refill.");
    }
}


