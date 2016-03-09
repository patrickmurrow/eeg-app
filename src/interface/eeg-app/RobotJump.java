import java.awt.Robot;
import java.awt.event.KeyEvent;

public class RobotJump {
	public static void main(String args[]){
		try{
			Robot r = new Robot();
			int keyCode = KeyEvent.VK_SPACE; // the A key
			r.keyPress(keyCode);
			// later...
			r.keyRelease(keyCode);
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}

