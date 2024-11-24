# FlockingBehaviors

I was assigned to investigate flocking behavior AI. The goal was to spawn as many agents as possible that have the following steering behaviors:

Seek / Flee / Arrive / Wander / Pursuit / Evade

I aimed to combine these steering behaviors to create an AI that moves agents effectively.

Because many agents with individual behaviors can cause performance loss (frame rate drop), I needed to use spatial partitioning. This technique divides space into multiple sub-spaces or partitions to aid in data processing and reduce unnecessary calculations.

In this project, I'm using flat partitioning.

**This project will be updated to use hierarchical partitioning with a tree structure for more performance-efficient techniques.**
