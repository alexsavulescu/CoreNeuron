/*
Copyright (c) 2014 EPFL-BBP, All rights reserved.

THIS SOFTWARE IS PROVIDED BY THE BLUE BRAIN PROJECT "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE BLUE BRAIN PROJECT
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "corebluron/nrnconf.h"
#include "corebluron/nrniv/nrniv_decl.h"
#include "corebluron/nrniv/output_spikes.h"
#include "corebluron/nrnmpi/nrnmpi.h"

int spikevec_buffer_size;
int spikevec_size;
double* spikevec_time;
int* spikevec_gid;

void mk_spikevec_buffer(int sz) {
  spikevec_buffer_size = sz;
  spikevec_size = 0;
  spikevec_time = new double[sz];
  spikevec_gid = new int[sz];
}

void output_spikes() {
  char fname[100];
  sprintf(fname, "out%d.dat", nrnmpi_myid);
  FILE* f = fopen(fname, "w");
  for (int i=0; i < spikevec_size; ++i)
  {
    if (spikevec_gid[i] > -1)
      fprintf(f, "%.10g\t%d\n", spikevec_time[i], spikevec_gid[i]);
  }
  fclose(f);
}


void validation(std::vector<std::pair<double,int> >& res)
{
   for (int i=0; i < spikevec_size; ++i)
       res.push_back(std::make_pair(spikevec_time[i], spikevec_gid[i]));
}