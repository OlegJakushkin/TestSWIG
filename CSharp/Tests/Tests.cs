using System;
using System.Threading;
using LibraryNamespace;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Tests {
    internal class Abra: A {
        public override void SetName( string n ) {
            base.SetName( "C# 666" );
        }

        public override string SayHello() {
            Console.WriteLine( "C# Hell is upon SWIG" );
            return "C# Hell!";
        }
    }

    internal class Baba: B {
        public override void SetA( A p ) {
            Console.WriteLine( "C# ruls?" );
            base.SetA( p );
        }
    }

    [TestClass]
    public class Tests {
        [TestMethod]
        private static void GetValue3() {
            Console.WriteLine( "SharedPtr + Inheritance scope game test" );
            var b3 = new Baba();
            {
                var a3 = new Abra();
                a3.SetName( "rar" );
                b3.SetA( a3 );
            }
            Assert.AreEqual( b3.CallA(), "C++ Hello! from C++ to C++ Call A:C++ rar" );
            GC.Collect();
            Thread.Sleep( 1000 );

            Assert.AreEqual( b3.CallA(), "C++ Hello! from C++ to C++ Call A:C++ rar" );
        }

        [TestMethod]
        private static void GetValue2() {
            Console.WriteLine( "Inheritance test" );
            var a2 = new Abra();
            var b2 = new Baba();
            a2.SetName( "hell" );
            a2.SayHello();
            b2.SetA( a2 );
            Assert.AreEqual( b2.CallA(), "C++ Hello! from C++ to C++ Call A:C++ hell" );
        }

        [TestMethod]
        private static void GetValue() {
            var a = new A();
            var b = new B();

            Console.WriteLine( "A test" );
            a.SetName( "Bla-Bla" );
            Assert.AreEqual( a.SayHello(), "C++ Bla-Bla" );
            

            Console.WriteLine( "B test" );
            b.SetA( a );
            Assert.AreEqual( a.SayHello(), "C++ Hello! from C++ to C++ Call A:C++ " );
        }
    }
}
  