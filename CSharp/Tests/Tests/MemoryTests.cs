using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Tests {
    [TestClass]
    public class MemoryTests {
        private void ClearGC() {
            GC.Collect();
            GC.Collect( GC.MaxGeneration );
            GC.WaitForPendingFinalizers();
            GC.Collect();
            GC.WaitForFullGCApproach();
            GC.WaitForFullGCComplete();
            GC.Collect();
        }

        [TestMethod]
        public void TestWithUsing() {
            using ( var a = new CSharpAwithDestructor() ) {
            using ( var b = new CSharpB() ) {
                    a.SetName( "rar" );
                    b.SetA( a );

                    Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() );
                }
            }
            ClearGC();
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
                ClearGC();
                Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() );
            }
            ClearGC();
            Assert.AreEqual( "C++ Call A:C# Hell!", b.CallA() ); // How to keep shared_ptr passed object as long as C++ needs it?
        }

        [TestMethod]
        public void TestWithNew() {
            TestScope();
            ClearGC();
            Assert.AreEqual( CSharpAwithDestructor.State.Destroyed, CSharpAwithDestructor.LastState );
        }
    }
}