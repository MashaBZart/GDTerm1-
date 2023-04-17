import unreal

#define actor location

actorLocation = unreal.Vector(0, 0, 1000)
actorRotaton = unreal.Rotator(0, 0, 0)
levelSubSys= unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)

#create new atmospheric actors

dirLight = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.DirectionalLight, actorLocation, actorRotaton, False)

skyLight = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyLight, actorLocation, actorRotaton, False)

sky = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.SkyAtmosphere, actorLocation, actorRotaton, False)

fog = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.ExponentialHeightFog, actorLocation, actorRotaton, False)

clouds = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.VolumetricCloud, actorLocation, actorRotaton, False)

#save level with atmospherics

levelSubSys.save_current_level()

