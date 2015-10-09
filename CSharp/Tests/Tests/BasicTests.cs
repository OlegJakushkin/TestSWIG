using LibraryNamespace;
using NUnit.Framework;

namespace Tests {
    [TestFixture]
    public class BasicTests {
        [Test]
        public void TestInheritedFunctionCallFromCpp() {
            var a = new CSharpA();
            var b = new CSharpB();
            a.SetName( "bob" );
            a.SayHello();
            b.SetA( a );
            Assert.AreEqual(  "C++ Call A:C# Hell!", b.CallA() );
        }

        [Test]
        public void TestCppLibraryObjectB() {
            var a = new A();
            var b = new B();
            a.SetName( "bob" );
            b.SetA( a );
            Assert.AreEqual( "C++ Call A:C++ bob", b.CallA() );
        }

        [Test]
        public void TestCppLibraryObjectA() {
            var a = new A();
            a.SetName( "bob" );
            Assert.AreEqual( "C++ bob", a.SayHello() );
        }
    }
}
  