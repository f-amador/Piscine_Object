#!/bin/bash

# Docker image download and delete loop script
# This script pulls and deletes the same Docker image 100 times

IMAGE="alpine:latest"  # Lightweight image (~7MB)
ITERATIONS=100

echo "Starting Docker image pull/delete loop..."
echo "Image: $IMAGE"
echo "Iterations: $ITERATIONS"
echo ""

for i in $(seq 1 $ITERATIONS); do
    echo "[$i/$ITERATIONS] Pulling $IMAGE..."
    docker pull "$IMAGE" > /dev/null 2>&1
    
    if [ $? -eq 0 ]; then
        echo "[$i/$ITERATIONS] Deleting $IMAGE..."
        docker rmi "$IMAGE" > /dev/null 2>&1
    else
        echo "[$i/$ITERATIONS] Error pulling image"
    fi
done

echo ""
echo "Completed $ITERATIONS iterations!"

# Optional: Prune unused Docker resources
# Uncomment the line below to clean up dangling images
# docker image prune -f
