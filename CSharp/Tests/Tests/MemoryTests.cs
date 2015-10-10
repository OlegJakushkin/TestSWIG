using System;
using NUnit.Framework;

namespace Tests {
    [TestFixture]
    public class MemoryTests {
        private void ClearGC() {
            GC.Collect();
            GC.Collect( GC.MaxGeneration );
            GC.WaitForPendingFinalizers();
            GC.Collect();
            #if !MONO
            GC.WaitForFullGCApproach();
            GC.WaitForFullGCComplete();
            #endif
            GC.Collect();
        }

        [Test]
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

        [Test]
        public void TestWithNew() {
            TestScope();
            ClearGC();
            Assert.AreEqual( CSharpAwithDestructor.State.Destroyed, CSharpAwithDestructor.LastState );
        }
    }
}