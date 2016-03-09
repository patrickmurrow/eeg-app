#define H_PI 3.1415926535897932384626433832795L
#define SAMPLE_RATE 512
#define NUM_SAMPLES SAMPLE_RATE
//#define ALPHA 0.53836
//#define BETA  0.46164
#define ALPHA 0.54
#define BETA  0.46
#define SAM_LEN 600
#define BASELINE_LEN 61
#define ARTIFACT_LEN 1
#define TRIAL_LEN 8
#define NUM_SAM_BASELINE (BASELINE_LEN*2-1)
#define NUM_SAM_TRIAL (TRIAL_LEN*2)
//#define FISHER_THRESHOLD 1.53 /* for 59/121 2-tail F-distribution */
#define FISHER_THRESHOLD 6.0 /* temporary setting */
//#define T_DISTRIBUTION 1.9732 /* for 2-tail 0.05 (97.5%) df 121+59 */
#define T_DISTRIBUTION 3.0 /* for Zhiyi's setting */
//#define T_DISTRIBUTION 5.0 /* for Stephen Markham's setting */

enum parserstate {SEEK=0, SYNC, PSTART, PCODE, RAWLEN, RAWEEG, CHKSUM, NOTEEG};
void parser(unsigned char *buf, int len);
volatile int sample_count, state_switch;
volatile int gui_on, psycho_start;
double *eegdata;
FILE *dfp;
