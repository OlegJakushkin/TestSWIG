using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Tests {
    [TestClass]
    public class MemoryTests {
        [TestMethod]
        public void TestSharedPointerLiveCicleWithUsing() {
            using ( var b = new CSharpB() ) {
                using ( var a = new CSharpAwithDestructor() ) {
                    a.SetName( "rar" );
                    b.SetA( a );

                    Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() );
                }
                Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() );
            }
            GC.Collect();
            GC.WaitForFullGCComplete();
            Assert.AreEqual( CSharpAwithDestructor.State.Destroyed, CSharpAwithDestructor.LastState );
        }


        private void TestInnerScope(CSharpB b) {
            var a = new CSharpAwithDestructor();
            a.SetName( "rar" );
            b.SetA( a );
        }

        void TestScope() {
            var b = new CSharpB();
            {
                TestInnerScope(b);
                Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() );
            }

            GC.Collect();
            GC.Collect( GC.MaxGeneration );
            GC.WaitForPendingFinalizers();
            GC.Collect();
            GC.WaitForFullGCApproach();
            GC.WaitForFullGCComplete();
            GC.Collect();

            Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() ); // How to keep shared_ptr passed object as long as C++ needs it?
        }

        [TestMethod]
        public void TestSharedPointerLiveCicleWithNew() {
            TestScope();

            GC.Collect();
            GC.Collect(GC.MaxGeneration);
            GC.WaitForPendingFinalizers();
            GC.Collect();
            GC.WaitForFullGCApproach();
            GC.WaitForFullGCComplete();
            GC.Collect();

            Assert.AreEqual( CSharpAwithDestructor.State.Destroyed, CSharpAwithDestructor.LastState );
        }
    }
}