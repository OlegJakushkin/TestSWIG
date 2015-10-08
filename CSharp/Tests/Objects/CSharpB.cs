using System;
using System.Collections.Generic;
using LibraryNamespace;

namespace Tests {
    internal class CSharpB: B {

        // One Must replecate an object keept via shared_ptr in Proxy language object (for GC not to eat it);
        // Use List for multiple delegates (this will probably add a lock to client code!)
        // ReSharper disable once NotAccessedField.Local
        private A _keeperOfA; 
        public override void SetA( A p ) {
            Console.WriteLine( "C# ruls." );
            _keeperOfA = p;
            base.SetA( p );
        }

    }
}