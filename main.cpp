#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkInteractorStyleImage.h>
#include <vtkPNGReader.h> // Or any other image reader
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

int main(int argc, char* argv[]) {
    // A simple check for the image file
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.png>" << std::endl;
        return EXIT_FAILURE;
    }

    // 1. Read the image from file
    vtkNew<vtkPNGReader> reader;
    reader->SetFileName(argv[1]);
    reader->Update();

    vtkImageData* imageData = reader->GetOutput();
    int* imageDims = imageData->GetDimensions();
    std::cout << "Image dimensions: " << imageDims[0] << " x " << imageDims[1] << std::endl;

    // 2. Create an actor to display the image
    vtkNew<vtkImageActor> imageActor;
    imageActor->SetInputData(imageData);

    // 3. Set up the standard VTK rendering pipeline
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(imageActor);
    renderer->SetBackground(0.2, 0.3, 0.4); // Set a background color

    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer);
    
    // CRITICAL: Set the window size to the image dimensions
    renderWindow->SetSize(imageDims[0], imageDims[1]);

    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
    renderWindowInteractor->SetRenderWindow(renderWindow);

    // Use a 2D-friendly interactor style
    vtkNew<vtkInteractorStyleImage> style;
    renderWindowInteractor->SetInteractorStyle(style);

    // 4. Configure the camera for 1:1 mapping
    vtkCamera* camera = renderer->GetActiveCamera();

    // CRITICAL: Enable parallel projection
    camera->ParallelProjectionOn();

    // Calculate the center of the image
    double origin[3];
    double spacing[3];
    imageData->GetOrigin(origin);
    imageData->GetSpacing(spacing);

    double centerX = origin[0] + 0.5 * (imageDims[0] - 1) * spacing[0];
    double centerY = origin[1] + 0.5 * (imageDims[1] - 1) * spacing[1];
    
    // Set the camera to look at the center of the image
    camera->SetFocalPoint(centerX, centerY, 0.0);
    camera->SetPosition(centerX, centerY, 1.0); // Z distance doesn't affect scale in parallel projection
    camera->SetViewUp(0, 1, 0);
    
    // CRITICAL: Set the parallel scale to half the image height
    // This makes the viewport height equal to the image height in world coordinates
    // We assume a pixel spacing of 1.0 here for simplicity
    camera->SetParallelScale(imageDims[1] / 2.0);

    // Render and start the interaction
    renderWindow->Render();
    renderWindow->SetWindowName("1:1 Image Viewer");
    renderWindowInteractor->Initialize();
    renderWindowInteractor->Start();

    return EXIT_SUCCESS;
}
