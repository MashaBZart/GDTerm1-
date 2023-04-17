import unreal

actorLocation = unreal.Vector(0, 0, 0)
actorRotaton = unreal.Rotator(0, 0, 0)
landskape = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.Landscape, actorLocation, actorRotaton, False)